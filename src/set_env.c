/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:21:05 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 09:40:02 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int update_env(char *label, char *value, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], label, ft_strlen(label)))
		{
			free(env[i]);
			env[i] = merge_string(label, "=", value);
			return (0);
		}
		i++;
	}
	return (1);
}

int	add_env_var_to_list(char *new_env_var, char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = ft_calloc(i + 2, sizeof(char *));
	if (!new_env)
		return (1);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
		{
			free_2d(new_env);
			return (1);
		}
		i++;
	}
	new_env[i] = new_env_var;
	free_2d(env);
	env = new_env;
	return (0);
}

int set_env(char *label, char *value, char **env)
{
	int	ret;

	ret = update_env(label, value, env);
	if (ret == 0)
		return (0);
	ret = add_env_var_to_list(merge_string(label, "=", value), env);
	return (ret);
}
