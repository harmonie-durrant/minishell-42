/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:44:55 by rbryento          #+#    #+#             */
/*   Updated: 2024/03/12 13:03:51 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	char	flag;
	int		(*funct)(va_list list, size_t *len);
}	t_flags;

int	flag_c(va_list list, size_t *len);
int	flag_s(va_list list, size_t *len);
int	flag_p(va_list list, size_t *len);
int	flag_d(va_list list, size_t *len);
int	flag_i(va_list list, size_t *len);
int	flag_u(va_list list, size_t *len);
int	flag_x(va_list list, size_t *len);
int	flag_xx(va_list list, size_t *len);

int	ft_nbrlen(int nb);
int	ft_nbrulen(unsigned int nb);
int	ft_nbrdlen(int nb);

#endif