/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:57:00 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 12:59:45 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*t;

	t = begin_list;
	if (t != 0)
	{
		while (t->next != 0)
		{
			if (cmp(t->data, data_ref) == 0)
				f(t->data);
			t = t->next;
		}
		if (cmp(t->data, data_ref) == 0)
			f(t->data);
	}
}
