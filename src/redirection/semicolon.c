/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:06:34 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/29 15:24:34 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	semicolon_handler(t_minishell *mini_data, char **args)
{
	int		i;
	char	**cmd_after_semicolon;
	pid_t	pid;

	i = get_index_arg(args, ";");
	if (!args[i])
		return (1);
	args[i] = NULL;
	pid = fork();
	if (pid == 0)
	{
		find_command(mini_data, args);
		exit(0);
	}
	else
	{
		wait(NULL);
		cmd_after_semicolon = &args[i + 1];
		find_command(mini_data, cmd_after_semicolon);
		wait(NULL);
	}
	return (0);
}
