/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:01:59 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 15:38:56 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env(const char *name, t_minishell *ms_data)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	while (ms_data->env[i])
		i++;
	new_env = calloc(i, sizeof(char *));
	i = 0;
	j = 0;
	while (ms_data->env[i])
	{
		if (ft_strncmp(name, ms_data->env[i], ft_strlen(name)) != 0)
		{
			new_env[j] = ms_data->env[i];
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	free_2d(ms_data->env);
	ms_data->env = new_env;
	return (0);
}
