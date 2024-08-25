/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbflags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:02:32 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/10 15:40:26 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_p(va_list list, size_t *len)
{
	unsigned long int	nb;

	nb = va_arg(list, unsigned long int);
	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*len = *len + 5;
		return (1);
	}
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	*len = *len + 2;
	ft_putnbr_base_fd(nb, "0123456789abcdef", 1, len);
	return (1);
}

int	flag_d(va_list list, size_t *len)
{
	int	nb;

	nb = va_arg(list, int);
	ft_putnbr_fd(nb, 1);
	*len = *len + ft_nbrdlen(nb);
	return (1);
}

int	flag_i(va_list list, size_t *len)
{
	int	nb;

	nb = va_arg(list, int);
	ft_putnbr_fd(nb, 1);
	*len = *len + ft_nbrlen(nb);
	return (1);
}

int	flag_u(va_list list, size_t *len)
{
	unsigned int	nb;

	nb = va_arg(list, unsigned int);
	ft_putnbru_fd(nb, 1);
	*len = *len + ft_nbrulen(nb);
	return (1);
}
