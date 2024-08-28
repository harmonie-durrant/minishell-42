/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:51 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 09:40:00 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_env(const char *name, const char *value)
{
	int		name_len;
	int		value_len;
	char	*new_var;
	int		i;
	int		j;

	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	new_var = calloc(name_len + value_len + 2, sizeof(char));
	i = 0;
	while (name[i])
	{
		new_var[i] = name[i];
		i++;
	}
	new_var[i] = '=';
	i++;
	j = 0;
	while (value[j])
	{
		new_var[i + j] = value[j];
		j++;
	}
	new_var[i + j] = '\0';
	return (new_var);
}
