/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:06:49 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 13:35:09 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command(t_minishell *ms_data, t_tree *branch)
{
	char	**args;
	int		res;

	args = get_args(branch->data);
	if (!args)
		return (1);
	res = handle_builtins(ms_data, args);
	if (res == -1)
		if (get_redirection(ms_data, args) == 2)
			res = find_command(ms_data, args);
	free_2d(args);
	return (res);
}

int	handle_seperators(t_minishell *ms_data, t_tree *branch)
{
	int	res;

	res = 0;
	if (!ft_strncmp(branch->data, ";", 1) || !ft_strncmp(branch->data, "&", 1))
	{
		if (branch->left != NULL)
			res = execute_tree(ms_data, branch->left);
		if (branch->right != NULL && res == 0)
			res = execute_tree(ms_data, branch->right);
		return (res);
	}
	res = execute_piped_commands(ms_data, branch);
	return (res);
}

int	execute_piped_commands(t_minishell *ms_data, t_tree *branch)
{
	t_pipepids	pipepids;
	int			status;
	int			pipe_fd[2];
	pid_t		pids[2];

	status = 0;
	if (!branch)
		return (1);
	if (ft_strncmp(branch->data, "|", 1) != 0)
		return (execute_command(ms_data, branch));
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe failed");
		return (1);
	}
	pipepids.pipe_fd = pipe_fd;
	pipepids.pids = pids;
	leftright_pid(ms_data, branch, &pipepids);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pids[0], &status, 0);
	waitpid(pids[1], &status, 0);
	return (0);
}

int	execute_tree(t_minishell *ms_data, t_tree *branch)
{
	int	ret;

	if (!branch)
		return (0);
	ret = handle_seperators(ms_data, branch);
	return (ret);
}
