/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args-ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:24:03 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 13:31:26 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_arg_ext(char *data, t_v2d *ignore, char *argsn, int *i)
{
	int	j;

	j = 0;
	while (data[*i])
	{
		if (data[*i] == '\'' && ignore->x == 0)
			ignore->y = !ignore->y;
		if (data[*i] == '"' && ignore->y == 0)
			ignore->x = !ignore->x;
		if (data[*i] == ' ' && ignore->x == 0 && ignore->y == 0)
			break ;
		argsn[j] = data[*i];
		j++;
		*i = *i + 1;
	}
}

void	add_arg(char *data, int *i, char **args, t_v2d *ignore)
{
	int	j;
	int	n;

	j = 0;
	n = 0;
	while (args[n])
		n++;
	while (data[*i + j])
	{
		if (data[*i + j] == '\'' && ignore->x == 0)
			ignore->y = !ignore->y;
		if (data[*i + j] == '"' && ignore->y == 0)
			ignore->x = !ignore->x;
		if (data[*i + j] == ' ' && ignore->x == 0 && ignore->y == 0)
			break ;
		j++;
	}
	args[n] = calloc(j + 1, sizeof(char));
	add_arg_ext(data, ignore, args[n], i);
	args[n][j] = '\0';
}
