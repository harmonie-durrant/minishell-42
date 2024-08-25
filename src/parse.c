/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:24:16 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 16:37:47 by rbryento         ###   ########.fr       */
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

void	parse_input(char *input, t_minishell *mini_data)
{
	if (!mini_data->history)
		mini_data->history = ft_lstnew(input);
	else
		ft_lstadd_front(&mini_data->history, ft_lstnew(input));
	format_input(input);
	ft_printf("[%s]\n", input);
	if (input[0] == '\0')
		return ;
	mini_data->tree = process_tree(input);
}
