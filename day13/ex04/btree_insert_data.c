/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:26:17 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/09 12:32:41 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	if (*root == (void *)0)
	{
		*root = btree_create_node(item);
	}
	else
	{
		if (cmpf(item, (*root)->item) < 0)
		{
			if ((*root)->left == (void*)0)
				(*root)->left = btree_create_node(item);
			else
				btree_insert_data(&(*root)->left, item, cmpf);
		}
		else
		{
			if ((*root)->right == (void*)0)
				(*root)->right = btree_create_node(item);
			else
				btree_insert_data(&(*root)->right, item, cmpf);
		}
	}
}
