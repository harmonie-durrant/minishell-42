/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:15:41 by rbryento          #+#    #+#             */
/*   Updated: 2024/07/01 10:47:08 by rbryento         ###   ########.fr       */
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

static void	add_arg(char *data, int *i, char **args, int *ignore, int *ignore_alt)
{
	int	j;
	int n;

	j = 0;
	n = 0;
	while (args[n])
		n++;
	while (data[*i + j])
	{
		if (data[*i + j] == '\'' && *ignore == 0)
			*ignore_alt = !*ignore_alt;
		if (data[*i + j] == '"' && *ignore_alt == 0)
			*ignore = !*ignore;
		if (data[*i + j] == ' ' && *ignore == 0 && *ignore_alt == 0)
			break ;
		j++;
	}
	args[n] = calloc(j + 1, sizeof(char));
	j = 0;
	while (data[*i])
	{
		if (data[*i] == '\'' && *ignore == 0)
			*ignore_alt = !*ignore_alt;
		if (data[*i] == '"' && *ignore_alt == 0)
			*ignore = !*ignore;
		if (data[*i] == ' ' && *ignore == 0 && *ignore_alt == 0)
			break ;
		args[n][j] = data[*i];
		j++;
		*i = *i + 1;
	}
	args[n][j] = '\0';
}

static void	make_args(char **args, char *data)
{
	int	i;
	int	ignore;
	int	ignore_alt;

	i = 0;
	ignore = 0;
	ignore_alt = 0;
	while (data[i])
	{
		if (ignore == 0 && ignore_alt == 0 && data[i] != ' ')
		{
			add_arg(data, &i, args, &ignore, &ignore_alt);
			continue ;
		}
		if (data[i] == '\'' && ignore == 0)
			ignore_alt = !ignore_alt;
		if (data[i] == '"' && ignore_alt == 0)
			ignore = !ignore;
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
