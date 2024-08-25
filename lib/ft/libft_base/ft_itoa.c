/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:47:01 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/07 11:57:32 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_handlenitoa(long *num, char *ns)
{
	if (*num < 0)
	{
		ns[0] = '-';
		*num = *num * -1;
	}
}

char	*ft_itoa(int n)
{
	char	*ns;
	int		len;
	long	num;

	num = n;
	len = ft_numlen(n);
	ns = malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (0);
	if (num == 0)
	{
		ns[0] = '0';
		ns[1] = '\0';
		return (ns);
	}
	ft_handlenitoa(&num, ns);
	ns[len] = '\0';
	while (num > 0)
	{
		ns[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (ns);
}
