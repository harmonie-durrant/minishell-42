/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:47:21 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/07 13:39:08 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cinstr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	end = (size_t)ft_strlen((char *)s1);
	while (ft_cinstr(s1[start], (char *)set))
		start = start + 1;
	while (ft_cinstr(s1[end - 1], (char *)set))
		end = end - 1;
	if (end <= start)
		end = start;
	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, (char const *)(s1 + start), end - start);
	str[end - start] = '\0';
	return (str);
}
