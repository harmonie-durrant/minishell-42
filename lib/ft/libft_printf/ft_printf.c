/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:56:54 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/10 14:51:18 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(unsigned int num, int base, int cap)
{
	char	rep[17];
	char	buffer[50];
	char	*ptr;

	if (num == 0)
		return ("0");
	if (cap == 0)
		ft_strlcpy(rep, "0123456789abcdef", base);
	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*--ptr = rep[num % base];
		num = num / base;
	}
	return (ptr);
}

static int	ft_print_arg(char *str, va_list args, size_t *size)
{
	int				i;
	const t_flags	flags[] = {
	{'s', flag_s}, {'c', flag_c}, {'p', flag_p}, {'d', flag_d},
	{'i', flag_i}, {'u', flag_u}, {'x', flag_x}, {'X', flag_xx}
	};

	i = 0;
	if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		*size = *size + 1;
		return (1);
	}
	while (i < 8)
	{
		if (flags[i].flag == *str)
			return (flags[i].funct(args, size));
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	size;
	int		i;
	va_list	list;

	size = 0;
	i = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
			i += ft_print_arg((char *)(format + i + 1), list, &size);
		else
		{
			ft_putchar_fd(format[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}
