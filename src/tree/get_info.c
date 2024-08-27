/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:07:05 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 16:57:51 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_seperator(char *input, size_t j)
{
	int	i;
	int	ignore;
	int	ignore_alt;

	ignore = 0;
	ignore_alt = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '"' && ignore_alt == 0)
			ignore = !ignore;
		if (input[i] == '\'' && ignore == 0)
			ignore_alt = !ignore_alt;
		if (input[i] == P_CHARS[j] && (ignore == 0 && ignore_alt == 0))
			return (i);
		i++;
	}
	return (-1);
}

int	get_seperator_index(char *input)
{
	int		ret;
	size_t	j;

	j = 0;
	while (P_CHARS[j] != '\0')
	{
		ret = check_seperator(input, j);
		if (ret != -1)
			return (ret);
		j++;
	}
	return (-1);
}
