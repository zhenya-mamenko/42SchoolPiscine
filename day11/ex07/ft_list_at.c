/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:24:46 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 11:28:41 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;
	t_list			*t;

	count = 0;
	t = 0;
	if (begin_list != 0)
	{
		t = begin_list;
		while (t->next != 0 && count != nbr)
		{
			count += 1;
			t = t->next;
		}
		if (count != nbr)
			t = 0;
	}
	return (t);
}
