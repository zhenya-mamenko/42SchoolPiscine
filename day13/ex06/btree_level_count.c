/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:37:27 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/09 13:49:47 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		counting(t_btree *n, int count)
{
	int l;
	int r;

	if (n == (void *)0)
		return (count);
	if ((l = counting(n->left, count + 1)) >
		(r = counting(n->right, count + 1)))
		return (l);
	else
		return (r);
}

int		btree_level_count(t_btree *root)
{
	int	count;

	if (root == (void*)0)
		return (0);
	return (counting(root, 0));
}
