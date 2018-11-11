/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:12:19 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/09 13:34:07 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void	*result;

	if (root == (void*)0)
		return ((void*)0);
	if (cmpf(data_ref, root->item) < 0 &&
		(result = btree_search_item(root->left, data_ref, cmpf)))
		return (result);
	if (cmpf(data_ref, root->item) == 0)
		return (result);
	if (cmpf(data_ref, root->item) >= 0 &&
		(result = btree_search_item(root->right, data_ref, cmpf)))
		return (result);
	return ((void*)0);
}
