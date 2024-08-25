/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexaflags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:06:49 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/10 15:44:56 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_x(va_list list, size_t *len)
{
	unsigned int	nb;

	nb = va_arg(list, unsigned int);
	ft_putnbr_base_fd((unsigned long int)nb, "0123456789abcdef", 1, len);
	return (1);
}

int	flag_xx(va_list list, size_t *len)
{
	unsigned int	nb;

	nb = va_arg(list, unsigned int);
	ft_putnbr_base_fd((unsigned long int)nb, "0123456789ABCDEF", 1, len);
	return (1);
}
