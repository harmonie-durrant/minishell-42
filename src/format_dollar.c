/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:45:10 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 11:23:40 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_char(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	return (new_str);
}

char	*add_str(char *str, char *add)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = ft_calloc(ft_strlen(str) + ft_strlen(add) + 1, sizeof(char));
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	i = 0;
	while (add[i])
	{
		new_str[j] = add[i];
		i++;
		j++;
	}
	free(str);
	return (new_str);
}

int	set_ignore(char *str, t_v2d *ij, char **formatted, t_v2d *ignore)
{
	if (str[ij->x] == '\'' && ignore->x == 0)
	{
		ignore->y = !ignore->y;
		*formatted = add_char(*formatted, str[ij->x]);
		ij->x = ij->x + 1;
		return (1);
	}
	if (str[ij->x] == '\"' && ignore->y == 0)
	{
		ignore->x = !ignore->x;
		*formatted = add_char(*formatted, str[ij->x]);
		ij->x = ij->x + 1;
		return (1);
	}
	return (0);
}

char	*format_dollar(char *str, t_minishell *mini_data)
{
	char	*formatted;
	t_v2d	ij;
	t_v2d	ignore;
	t_v4d	data;

	ij = (t_v2d){0, 0};
	ignore = (t_v2d){0, 0};
	formatted = ft_strdup("");
	data.ij = &ij;
	data.ignore = &ignore;
	while (str[ij.x])
	{
		if (set_ignore(str, &ij, &formatted, &ignore) == 1)
			continue ;
		if (check_no_dollar(str, &ij, &formatted) == 1)
			continue ;
		if (check_dollar(str, &data, &formatted, mini_data) == 1)
			continue ;
		formatted = add_char(formatted, str[ij.x]);
		ij.x = ij.x + 1;
	}
	return (formatted);
}
