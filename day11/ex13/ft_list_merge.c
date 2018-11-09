/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:08:43 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 20:27:00 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*t;

	t = *begin_list1;
	if (t != 0)
	{
		while (t->next != 0)
		{
			t = t->next;
		}
		t->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
