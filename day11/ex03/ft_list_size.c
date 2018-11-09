/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:24:46 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 10:28:46 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*t;

	count = 0;
	if (begin_list != 0)
	{
		t = begin_list;
		count = 1;
		while (t->next != 0)
		{
			count += 1;
			t = t->next;
		}
	}
	return (count);
}
