/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:18:55 by rbryento          #+#    #+#             */
/*   Updated: 2023/10/09 21:26:33 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_nbrulen(unsigned int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_nbrdlen(int nb)
{
	return (ft_nbrlen(nb));
}
