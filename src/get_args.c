/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:15:41 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 13:24:18 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_nargs(char *data)
{
	int	i;
	int	n;
	int	ignore;
	int	ignore_alt;

	i = 0;
	n = 1;
	ignore = 0;
	ignore_alt = 0;
	while (data[i])
	{
		if (data[i] == '\'' && ignore == 0)
			ignore_alt = !ignore_alt;
		if (data[i] == '"' && ignore_alt == 0)
			ignore = !ignore;
		if (ignore == 0 && ignore_alt == 0 && data[i] == ' ')
			n++;
		i++;
	}
	return (n);
}

static void	make_args(char **args, char *data)
{
	int		i;
	t_v2d	ignore;

	i = 0;
	ignore.x = 0;
	ignore.y = 0;
	while (data[i])
	{
		if (ignore.x == 0 && ignore.y == 0 && data[i] != ' ')
		{
			add_arg(data, &i, args, &ignore);
			continue ;
		}
		if (data[i] == '\'' && ignore.x == 0)
			ignore.y = !ignore.y;
		if (data[i] == '"' && ignore.y == 0)
			ignore.x = !ignore.x;
		i++;
	}
}

char	**get_args(char *data)
{
	char	**args;
	int		nargs;

	if (!data)
		return (NULL);
	nargs = get_nargs(data);
	args = calloc(nargs + 1, sizeof(char *));
	make_args(args, data);
	args[nargs] = NULL;
	return (args);
}
