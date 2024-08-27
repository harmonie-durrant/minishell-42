/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:37:39 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 10:34:31 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*item;

	if (!lst || !del)
		return ;
	item = *lst;
	if (item)
	{
		while (item)
		{
			tmp = item->next;
			del(item->content);
			free(*lst);
			item = tmp;
		}
		if (item)
			free(item);
		item = NULL;
	}
}
