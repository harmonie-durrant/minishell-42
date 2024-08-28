/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:01:59 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 21:15:00 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env(const char *name, t_minishell *ms_data)
{
	int		i;
	int		j;
	char	**new_env;
	char	**split_tmp;
	char	*tmp;

	if (!name || !ms_data->env)
		return (1);
	i = 0;
	while (ms_data->env[i])
		i++;
	tmp = get_env((char *)name, ms_data->env);
	if (!tmp)
		return (0);
	free(tmp);
	new_env = ft_calloc(i, sizeof(char *));
	i = 0;
	j = 0;
	while (ms_data->env[i])
	{
		split_tmp = ft_split(ms_data->env[i], '=');
		if (ft_strncmp(split_tmp[0], name, ft_strlen(name)) != 0)
			new_env[j++] = ft_strdup(ms_data->env[i]);
		free_2d(split_tmp);
		i++;
	}
	new_env[j] = NULL;
	free_2d(ms_data->env);
	ms_data->env = new_env;
	return (0);
}
