/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_dbl_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:06:09 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/30 12:10:34 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_index_arg(char *arg, char *str)
{
	//find what arg in args contains str but not inside quotes
	int	i;
	t_v2d	ignore;

	i = 0;
	ignore = (t_v2d){0, 0};
	while (arg[i])
	{
		if (arg[i] == '\"' && !ignore.y)
			ignore.x = !ignore.x;
		if (arg[i] == '\'' && !ignore.x)
			ignore.y = !ignore.y;
		if (ft_strncmp(&arg[i], str, ft_strlen(str)) == 0 && !ignore.x && !ignore.y)
			return (1);
		i++;
	}
	return (0);
}

int	get_index_arg(char **args, char *str)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_index_arg(args[i], str) == 1)
			return (i);
		i++;
	}
	return (i);
}

int	redirect_double_output(t_minishell *mini_data, char **args)
{
	int		i;
	char	*double_arg;
	int		fd;
	pid_t	pid;

	i = get_index_arg(args, ">>");
	if (!args[i] || !args[i + 1])
		return (1);
	if (check_redirect_permissions(mini_data, args[i + 1]) == 1)
		return (1);
	args[i] = NULL;
	double_arg = remove_double_quotes(args[i + 1]);
	free(double_arg);
	args[i] = NULL;
	fd = open(args[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
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
