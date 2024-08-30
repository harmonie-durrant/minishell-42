/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:06:22 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/30 12:05:04 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_input(t_minishell *mini_data, char **args)
{
	int		i;
	int		fd;
	pid_t	pid;

	i = get_index_arg(args, "<");
	if (!args[i] || !args[i + 1])
		return (1);
	if (check_redirect_permissions(mini_data, args[i + 1]) == 1)
		return (1);
	args[i] = NULL;
	fd = open(args[i + 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(args[i + 1], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		mini_data->exit_code = 1;
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		find_command(mini_data, args);
		exit(0);
		return (0);
	}
	close(fd);
	waitpid(pid, &i, 0);
	if (WIFEXITED(i))
		mini_data->exit_code = WEXITSTATUS(i);
	return (0);
}
