/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:55:05 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/29 13:01:32 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_child(t_minishell *mini_data, char *full_path, char **args)
{
	int		status;
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
		execve(full_path, args, mini_data->env);
	else if (child_pid < 0)
	{
		ft_printf("Error: fork failed\n");
		return (127);
	}
	waitpid(child_pid, &status, 0);
	if (WIFEXITED(status))
		mini_data->exit_code = WEXITSTATUS(status);
	else
		ft_putstr_fd("minishell: child exited abnormally\n", 2);
	return (mini_data->exit_code);
}
