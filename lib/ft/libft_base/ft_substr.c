/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:47:24 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/09 11:15:23 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	slen;

	i = start;
	j = 0;
	slen = ft_strlen(s);
	if (len > slen)
	{
		len = slen;
	}
	new_str = (char *)malloc(len + 1);
	if (!s || !new_str)
		return (NULL);
	while (i < slen && j < len)
	{
		new_str[j] = s[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
