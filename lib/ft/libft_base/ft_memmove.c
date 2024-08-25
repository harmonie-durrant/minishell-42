/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:08:23 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/09 09:27:22 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revmemcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	int		nb;

	nb = n - 1;
	while (nb >= 0)
	{
		s1 = (char *)(dest + nb);
		s2 = (char *)(src + nb);
		*(unsigned char *)s1 = *(unsigned char *)s2;
		nb--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*res;

	if (!dest && !src)
		return (NULL);
	if (dest >= src && dest <= (dest + n))
		res = ft_revmemcpy(dest, src, n);
	else
		res = ft_memcpy(dest, src, n);
	return (res);
}
