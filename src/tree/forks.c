/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:10:33 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/29 15:17:51 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_left_pipe(t_minishell *mini_data, t_tree *branch, int *pipe_fd)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	exit(execute_tree(mini_data, branch->left));
}

void	exec_right_pipe(t_minishell *mini_data, t_tree *branch, int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	exit(execute_tree(mini_data, branch->right));
}

void	leftright_pid(t_minishell *mini_data, t_tree *branch,
			t_pipepids *pipepids)
{
	pid_t	*pids;
	int		*pipe_fd;

	pids = pipepids->pids;
	pipe_fd = pipepids->pipe_fd;
	pids[0] = fork();
	if (pids[0] == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pids[0] == 0)
		exec_left_pipe(mini_data, branch, pipe_fd);
	pids[1] = fork();
	if (pids[1] == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pids[1] == 0)
		exec_right_pipe(mini_data, branch, pipe_fd);
}
