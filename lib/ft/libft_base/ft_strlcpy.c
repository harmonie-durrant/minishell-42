/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:11:00 by rbryento          #+#    #+#             */
/*   Updated: 2024/06/17 09:29:43 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	lsrc;

	if (!dst || !src)
		return (0);
	lsrc = ft_strlen((char *)src);
	if (size == 0)
		return (lsrc);
	if (size > (size_t)lsrc)
	{
		ft_memcpy(dst, src, lsrc);
		dst[lsrc] = '\0';
	}
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	lsrc = ft_strlen((char *)src);
	return (lsrc);
}
