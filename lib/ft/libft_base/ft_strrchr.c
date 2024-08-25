/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:32:34 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/03 14:58:27 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		max;
	char	*res;

	res = NULL;
	i = 0;
	max = ft_strlen((char *)s);
	while (i <= max)
	{
		if (*(char *)(s + i) == (char)c)
			res = (char *)(s + i);
		i++;
	}
	return (res);
}
