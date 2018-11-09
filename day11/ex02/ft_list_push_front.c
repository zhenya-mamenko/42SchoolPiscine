/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:21:02 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 10:22:01 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*el;

	el = ft_create_elem(data);
	if (*begin_list == 0)
		*begin_list = el;
	else
	{
		el->next = *begin_list;
		(*begin_list) = el;
	}
}
