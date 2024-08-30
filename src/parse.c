/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:24:16 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/30 12:15:53 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	format_input(char *input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\t')
			input[i] = ' ';
		i++;
	}
	i = 0;
	while (input[i] == ' ')
	{
		j = i;
		while (input[j])
		{
			input[j] = input[j + 1];
			j++;
		}
	}
}

char	*seperate_redirections(char *str)
{
	char	*new_str;
	t_v2d	ij;
	t_v2d	ignore;

	ij = (t_v2d){0, 0};
	ignore = (t_v2d){0, 0};
	new_str = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[ij.x])
	{
		if (str[ij.x] == '\"' && !ignore.y)
			ignore.x = !ignore.x;
		if (str[ij.x] == '\'' && !ignore.x)
			ignore.y = !ignore.y;
		if ((str[ij.x] == '>' || str[ij.x] == '<') && !ignore.x && !ignore.y)
		{
			if (str[ij.x - 1] != ' ')
				new_str[ij.y++] = ' ';
			new_str[ij.y++] = str[ij.x];
			if (str[ij.x + 1] == str[ij.x])
			{
				new_str[ij.y++] = str[ij.x + 1];
				ij.x++;
			}
			if (str[ij.x + 1] != ' ')
				new_str[ij.y++] = ' ';
		}
		else
			new_str[ij.y++] = str[ij.x];
		ij.x++;
	}
	new_str[ij.y] = '\0';
	free(str);
	return (new_str);
}

void	parse_input(char *input, t_minishell *mini_data)
{
	char	*formated_dollar;

	if (!mini_data->history)
		mini_data->history = ft_lstnew(ft_strdup(input));
	else
		ft_lstadd_front(&(mini_data->history), ft_lstnew(ft_strdup(input)));
	format_input(input);
	if (ft_strchr(input, '<') || ft_strchr(input, '>'))
		input = seperate_redirections(input);
	formated_dollar = format_dollar(input, mini_data);
	if (input[0] == '\0')
		return ;
	if (!formated_dollar)
		return ;
	mini_data->tree = process_tree(formated_dollar);
}
