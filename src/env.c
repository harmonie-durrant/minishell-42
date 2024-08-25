/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:02:45 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 13:36:21 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_big(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_strwordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '\'')
	{
		if (i == 0 && str[i] == '?')
			return (1);
		i++;
	}
	return (i);
}

char	*get_env(char *label, char **env)
{
	char	**line;
	char	*data;
	int		i;
	int		eq;

	i = 0;
	while (env[i])
	{
		line = ft_split(env[i++], '=');
		if (!line || !line[0] || !line[1])
			continue ;
		eq = ft_strncmp(label, line[0], get_big(ft_strlen(line[0]),
					ft_strwordlen(label)));
		if (eq == 0)
			break ;
		eq = -1;
		free_2d(line);
	}
	if (!line || eq == -1)
		return (NULL);
	data = ft_calloc(ft_strlen(line[1]) + 1, sizeof(char));
	ft_strlcpy(data, line[1], ft_strlen(line[1]) + 1);
	free_2d(line);
	return (data);
}
