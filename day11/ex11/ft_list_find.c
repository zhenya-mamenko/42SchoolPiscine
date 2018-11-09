/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:17:00 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 13:18:24 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*t;

	t = begin_list;
	if (t != 0)
	{
		while (t->next != 0)
		{
			if (cmp(t->data, data_ref) == 0)
				return (t);
			t = t->next;
		}
		if (cmp(t->data, data_ref) == 0)
			return (t);
	}
	return (0);
}
