/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:41:39 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 11:53:41 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_double_quotes_ext(char *new_str, char *str, int len)
{
	int		i;
	int		j;
	t_v2d	blocked;

	i = 0;
	j = 0;
	blocked.x = 0;
	blocked.y = 0;
	while (i++ <= len)
	{
		if (str[i - 1] == '\'' && !blocked.y)
		{
			blocked.x = !blocked.x;
			continue ;
		}
		if (str[i - 1] == '\"' && !blocked.x)
		{
			blocked.y = !blocked.y;
			continue ;
		}
		new_str[j] = str[i - 1];
		j++;
	}
}

static int	count_length_without_quotes(char *str, int len)
{
	int		i;
	int		j;
	t_v2d	blocked;

	i = 0;
	j = 0;
	blocked.x = 0;
	blocked.y = 0;
	while (i++ <= len)
	{
		if (str[i - 1] == '\'' && !blocked.y)
		{
			blocked.x = !blocked.x;
			continue ;
		}
		if (str[i - 1] == '\"' && !blocked.x)
		{
			blocked.y = !blocked.y;
			continue ;
		}
		j++;
	}
	return (j);
}

char	*remove_double_quotes(char *str)
{
	int		len;
	char	*new_str;

	len = count_length_without_quotes(str, ft_strlen(str));
	new_str = ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	remove_double_quotes_ext(new_str, str, len);
	return (new_str);
}
