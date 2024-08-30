/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sign_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:58:09 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/30 10:38:54 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redirection(t_minishell *mini_data, char **args)
{
	int	i;

	i = 0;
	(void)mini_data;
	(void)args;
	while (args[i])
	{
		if (ft_strncmp(args[i], ">>", get_big(2, ft_strlen(args[i]))) == 0)
			return (redirect_double_output(mini_data, args));
		if (ft_strncmp(args[i], "<<", get_big(2, ft_strlen(args[i]))) == 0)
			return (redirect_double_input(mini_data, args));
		if (ft_strncmp(args[i], ">", get_big(1, ft_strlen(args[i]))) == 0)
			return (redirect_output(mini_data, args));
		if (ft_strncmp(args[i], "<", get_big(1, ft_strlen(args[i]))) == 0)
			return (redirect_input(mini_data, args));
		i++;
	}
	return (2);
}
