/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:08:53 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 09:46:16 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_n_flag(int *i, char **args)
{
	int	flag_n;

	flag_n = 0;
	if (args[1] && !ft_strncmp(args[1], "-n", 2))
	{
		flag_n = 1;
		*i = *i + 1;
	}
	return (flag_n);
}

int	echo_builtin(t_minishell *mini_data, char **args)
{
	int		i;
	char	*formatted;
	int		flag_n;

	i = 1;
	flag_n = is_n_flag(&i, args);
	while (args[i])
	{
		formatted = remove_double_quotes(args[i]);
		ft_printf("%s", formatted);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (flag_n == 0)
		ft_printf("\n");
	mini_data->exit_code = 0;
	return (0);
}
