/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:27:29 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/02 20:44:21 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	position;
	int				delta;

	position = 0;
	while (position < n)
	{
		position++;
		delta = *(unsigned char *)s1 - *(unsigned char *)s2;
		s1++;
		s2++;
		if (delta)
			return (delta);
	}
	return (0);
}
