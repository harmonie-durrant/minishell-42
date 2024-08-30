/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_dbl_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:02:56 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/30 10:48:53 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_until(char *end)
{
	char	*line;
	int		flags;
	int		fd;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(end, flags, 0777);
	while (ft_strncmp(line, end, ft_strlen(end))
		|| ft_strlen(line) != ft_strlen(end))
	{
		free(line);
		line = readline("> ");
		if (ft_strlen(line) != ft_strlen(end))
			ft_putendl_fd(line, fd);
	}
	close(fd);
	free(line);
}

int	redirect_double_input(t_minishell *mini_data, char **args)
{
	int		i;
	pid_t	pid;
	int		fd;

	i = get_index_arg(args, "<<");
	if (!args[i] || !args[i + 1])
		return (1);
	if (check_redirect_permissions(mini_data, args[i + 1]) == 1)
		return (1);
	args[i] = NULL;
	read_until(args[i + 1]);
	fd = open(args[i + 1], O_RDONLY);
	pid = fork();
	args[i] = NULL;
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
	return (0);
}
