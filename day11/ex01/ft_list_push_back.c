/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:16:54 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 11:53:03 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*el;
	t_list	*t;

	el = ft_create_elem(data);
	if (*begin_list == 0)
		*begin_list = el;
	else
	{
		t = *begin_list;
		while (t->next != 0)
		{
			t = t->next;
		}
		t->next = el;
	}
}
