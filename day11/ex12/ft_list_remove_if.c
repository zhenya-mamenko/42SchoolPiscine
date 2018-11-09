/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:25:05 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 16:04:46 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*get_next(t_list *t, void *data_ref, int (*cmp)())
{
	t_list	*t2;

	while (t->next != 0 && cmp(t->next->data, data_ref) == 0)
	{
		t2 = t->next;
		t->next = t->next->next;
		free(t2);
	}
	return (t->next);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*t;
	t_list	t3;

	if (*begin_list != 0)
	{
		t3.next = *begin_list;
		t = &t3;
		while (t != 0 && t->next != 0)
		{
			t = get_next(t, data_ref, cmp);
		}
		*begin_list = t3.next;
	}
}
