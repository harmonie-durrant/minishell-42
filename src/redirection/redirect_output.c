/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:06:29 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/30 10:41:11 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirect_permissions(t_minishell *mini_data, char	*file)
{
	struct stat	buf;

	if (stat(file, &buf) == -1)
		return (0);
	if (stat(file, &buf) == 0)
	{
		if (buf.st_mode & S_ISDIR(buf.st_mode))
		{
			ft_putstr_fd(file, STDERR_FILENO);
			ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
			mini_data->exit_code = 1;
			return (1);
		}
		if (access(file, F_OK) == -1 || access(file, W_OK) == -1 || access(file, R_OK) == -1)
		{
			ft_putstr_fd(file, STDERR_FILENO);
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
			mini_data->exit_code = 1;
			return (1);
		}
	}
	return (0);
}

int	redirect_output(t_minishell *mini_data, char **args)
{
	int		i;
	int		fd;
	pid_t	pid;

	i = get_index_arg(args, ">");
	if (!args[i] || !args[i + 1])
		return (1);
	if (check_redirect_permissions(mini_data, args[i + 1]) == 1)
		return (1);
	args[i] = NULL;
	fd = open(args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		find_command(mini_data, args);
		exit(0);
		return (0);
	}
	close(fd);
	waitpid(pid, &i, 0);
	return (0);
}
