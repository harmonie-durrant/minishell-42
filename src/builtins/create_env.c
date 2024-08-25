/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:51 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 15:35:06 by rbryento         ###   ########.fr       */
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

void	add_env_var_to_list(char *new_var, t_minishell *ms_data)
{
	int		i;
	char	**new_env;

	i = 0;
	while (ms_data->env[i])
		i++;
	new_env = calloc(i + 2, sizeof(char *));
	i = 0;
	while (ms_data->env[i])
	{
		new_env[i] = ms_data->env[i];
		i++;
	}
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free_2d(ms_data->env);
	ms_data->env = new_env;
}
