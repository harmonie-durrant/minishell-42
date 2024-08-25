/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:55:05 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 13:24:27 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_directory_permission_denied(const char *path)
{
	if (access(path, X_OK) != -1)
	{
		fprintf(stderr, "%s: Permission denied.\n", path);
		exit(1);
	}
}

static void	handle_file_permission_denied(const char *path)
{
	if (access(path, X_OK) != -1)
	{
		fprintf(stderr, "%s: Permission denied.\n", path);
		exit(1);
	}
}

int	is_executable(char **args)
{
	struct stat	stats;

	if (errno == EACCES || errno == EPERM)
	{
		if (stat(args[0], &stats) != 0)
			exit(1);
		if (S_ISDIR(stats.st_mode))
			handle_directory_permission_denied(args[0]);
		if (S_ISREG(stats.st_mode))
			handle_file_permission_denied(args[0]);
	}
	return (0);
}

int	create_child(t_minishell *mini_data, char *full_path, char **args)
{
	int		status;
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(full_path, args, mini_data->env);
		is_executable(args);
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		ft_printf("Error: fork failed\n");
		return (127);
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
