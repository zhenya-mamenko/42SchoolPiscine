/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:44:25 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 12:52:05 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*t;

	t = begin_list;
	if (t != 0)
	{
		while (t->next != 0)
		{
			f(t->data);
			t = t->next;
		}
		f(t->data);
	}
}
