/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:06:56 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 12:41:22 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*create_node(char *data)
{
	t_tree	*node;

	node = NULL;
	if (!data)
		return (NULL);
	node = malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	add_node(t_tree *tree, char *data)
{
	if (tree == NULL)
	{
		tree = create_node(data);
		return (0);
	}
	if (tree->left == NULL)
	{
		tree->left = create_node(data);
		return (0);
	}
	if (tree->right == NULL)
	{
		tree->right = create_node(data);
		return (0);
	}
	return (1);
}

static int	get_max_string_length(t_tree *root)
{
	int	l_max;
	int	r_max;
	int	data_len;

	if (!root)
		return (0);
	l_max = get_max_string_length(root->left);
	r_max = get_max_string_length(root->right);
	data_len = ft_strlen(root->data);
	if (l_max > r_max)
	{
		if (l_max > data_len)
			return (l_max);
		return (data_len);
	}
	if (r_max > data_len)
		return (r_max);
	return (data_len);
}

void	print_tree(t_tree *root, int indent)
{
	int	max_string_length;
	int	i;

	i = 0;
	if (!root)
		return ;
	max_string_length = get_max_string_length(root);
	indent += max_string_length + 2;
	print_tree(root->right, indent);
	printf("\n");
	while (i < indent - max_string_length - 2)
	{
		ft_printf(" ");
		i++;
	}
	ft_printf("[%s]\n", root->data);
	print_tree(root->left, indent);
}

void	destroy_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	destroy_tree(tree->left);
	destroy_tree(tree->right);
	free(tree);
}
