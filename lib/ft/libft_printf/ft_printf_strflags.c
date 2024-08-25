/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strflags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:00:49 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/09 22:18:14 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_s(va_list list, size_t *len)
{
	char	*arg;

	arg = va_arg(list, char *);
	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*len = *len + 6;
		return (1);
	}
	ft_putstr_fd(arg, 1);
	*len = *len + ft_strlen(arg);
	return (1);
}

int	flag_c(va_list list, size_t *len)
{
	char	arg;

	arg = va_arg(list, int);
	ft_putchar_fd(arg, 1);
	*len = *len + 1;
	return (1);
}
