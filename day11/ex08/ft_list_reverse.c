/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:39:27 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 12:14:19 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*t;
	t_list	t2;

	if (*begin_list != 0)
	{
		t2 = **begin_list;
		(*begin_list)->next = 0;
		while (t2.next != 0)
		{
			t = t2.next;
			t2 = *t2.next;
			t->next = *begin_list;
			*begin_list = t;
		}
	}
}
