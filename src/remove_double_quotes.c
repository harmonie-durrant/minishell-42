/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:41:39 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 15:41:47 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_double_quotes(const char *str)
{
	int		i;
	int		j;
	int		blocked;
	int		blocked_alt;
	int		len;
	char	*new_str;

	blocked = 0;
	blocked_alt = 0;
	len = ft_strlen(str);
	new_str = malloc(len + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] == '\'' && !blocked_alt)
		{
			blocked = !blocked;
			i++;
			continue ;
		}
		if (str[i] == '\"' && !blocked)
		{
			blocked_alt = !blocked_alt;
			i++;
			continue ;
		}
		new_str[j] = str[i];
		j++;
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
