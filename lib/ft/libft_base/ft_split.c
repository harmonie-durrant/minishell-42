/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:47:13 by rbryento          #+#    #+#             */
/*   Updated: 2024/03/23 21:09:05 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	cond;

	i = 0;
	cond = 0;
	while (*str)
	{
		if (*str != c && cond == 0)
		{
			cond = 1;
			i++;
		}
		else if (*str == c)
			cond = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*new_word;
	int		i;

	i = 0;
	new_word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		new_word[i++] = str[start++];
	new_word[i] = '\0';
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	k = -1;
	i = 0;
	j = 0;
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			split[j++] = word_dup(s, k, i);
			k = -1;
		}
		else if (s[i] != c && k < 0)
			k = i;
		i++;
	}
	split[j] = 0;
	return (split);
}
