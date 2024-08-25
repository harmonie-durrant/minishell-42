/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:39 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/21 14:07:56 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		res = (char *)(s + i);
	return (res);
}
