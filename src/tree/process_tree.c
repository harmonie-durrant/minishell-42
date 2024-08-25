/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:07:01 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 12:45:13 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_padding(char *input, size_t i_sep, int *p_l, int *p_r)
{
	int	is_dbl;
	int	i;

	i = 0;
	is_dbl = 0;
	if (i_sep > 0)
		if (input[i_sep - 1] == ' ' || input[i_sep - 1] == '\t')
			*p_l = *p_l + 1;
	while (P_DOUBLES[i] != '\0')
	{
		if (input[i_sep + 1] == P_DOUBLES[i])
			is_dbl = is_dbl + 1;
		i++;
	}
	if (input[i_sep + 1] == ' ' || input[i_sep + 1] == '\t')
		*p_r = *p_r + 1;
	if (is_dbl > 0)
		*p_r = *p_r + 1;
	if (is_dbl > 0 && input[i_sep + 2])
		if (input[i_sep + 2] == ' ' || input[i_sep + 2] == '\t')
			*p_r = *p_r + 1;
	return (0);
}

static t_tree	*fill_values(char *input, size_t isep, int *p_l, int *p_r)
{
	char	*datal;
	char	*datar;
	char	*root_str;
	t_tree	*root;
	size_t	i_end;

	i_end = ft_strlen(input);
	if (*p_r == 1)
		root_str = ft_strndup(input + isep, *p_r);
	else
		root_str = ft_strndup(input + isep, *p_r + 1);
	root = create_node(root_str);
	if (isep != 0 && isep != i_end)
	{
		datal = ft_strndup(input, isep - *p_l);
		root->left = process_tree(datal);
		datar = ft_strndup(input + isep + *p_r + 1, i_end - isep - 1);
		root->right = process_tree(datar);
	}
	return (root);
}

t_tree	*process_tree(char *input)
{
	t_tree	*root;
	int		i_sep_int;
	size_t	i_sep;
	int		p_l;
	int		p_r;

	p_l = 0;
	p_r = 0;
	if (!input)
		return (NULL);
	i_sep_int = get_seperator_index(input);
	if (i_sep_int < 0)
		return (create_node(input));
	i_sep = (size_t)i_sep_int;
	set_padding(input, i_sep, &p_l, &p_r);
	root = fill_values(input, i_sep, &p_l, &p_r);
	return (root);
}
