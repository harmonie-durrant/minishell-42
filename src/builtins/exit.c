/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:51:30 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 09:05:48 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	str_is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_check_too_many(t_minishell *mini_data, char **args)
{
	if (args && args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		mini_data->exit_code = 1;
		mini_exit(mini_data);
	}
}

int	exit_builtin(t_minishell *mini_data, char **args)
{
	char	*tmp;

	exit_check_too_many(mini_data, args);
	ft_printf("exit\n");
	if (args[1])
	{
		tmp = ft_strdup(args[1]);
		free(args[1]);
		args[1] = remove_double_quotes(tmp);
		free(tmp);
		mini_data->exit_code = ft_atoi(args[1]);
		if (mini_data->exit_code < 0)
			mini_data->exit_code = 256 + mini_data->exit_code;
		if (str_is_all_digit(args[1]) == 0)
		{
			mini_data->exit_code = 2;
			ft_putstr_fd("minishell: numeric argument required\n", 2);
		}
	}
	free_2d(args);
	mini_exit(mini_data);
	return (0);
}
