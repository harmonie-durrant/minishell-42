/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:51:37 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 16:55:07 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_builtin(t_minishell *mini_data, char **args)
{
	(void)args;
	ft_printf("%s\n", getcwd(NULL, 0));
	mini_data->exit_code = 0;
	return (0);
}

int	unset_builtin(t_minishell *mini_data, char **args)
{
	int	i;

	i = 1;
	if (!args[1])
	{
		write(STDERR_FILENO, "unset: not enough arguments\n", 29);
		mini_data->exit_code = 1;
	}
	while (args[i])
	{
		unset_env(args[i], mini_data);
		i++;
	}
	mini_data->exit_code = 0;
	return (0);
}
