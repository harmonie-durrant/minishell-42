/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:38:56 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/07 22:06:58 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	val;
	int	i;

	sign = 1;
	val = 0;
	i = 0;
	while (str[i] == ' ' || ((str[i] > 8) && str[i] <= 13
			&& str[i] > 0))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		val = val * 10;
		val = val + (str[i] - '0');
		i++;
	}
	return (val * sign);
}
