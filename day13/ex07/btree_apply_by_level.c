/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:35:02 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/09 16:10:25 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_list	*ft_create_elem(void *data, int level)
{
	t_list *item;

	item = malloc(sizeof(t_list));
	item->next = (void *)0;
	item->item = data;
	item->level = level;
	item->is_first = 0;
	return (item);
}

void	ft_list_push_back(t_list **b, void *data, int level)
{
	t_list	*el;
	t_list	*t;

	el = ft_create_elem(data, level);
	if (*b == 0)
	{
		el->is_first = 1;
		*b = el;
	}
	else
	{
		t = *b;
		while (t->next != 0)
		{
			t = t->next;
		}
		t->next = el;
		if (t->level != level)
			el->is_first = 1;
	}
}

void	by_level(t_list **list,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list b;

	if (*list == (void *)0)
		return ;
	applyf((*list)->item, (*list)->level, (*list)->is_first);
	if ((*list)->item->left != (void *)0)
		ft_list_push_back(list, (*list)->item->left, (*list)->level + 1);
	if ((*list)->item->right != (void *)0)
		ft_list_push_back(list, (*list)->item->right, (*list)->level + 1);
	b = **list;
	free(*list);
	*list = b.next;
	by_level(list, applyf);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list *l;

	l = (t_list *)0;
	ft_list_push_back(&l, root, 0);
	by_level(&l, applyf);
}
