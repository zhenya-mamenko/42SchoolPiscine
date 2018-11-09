/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:21:02 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 13:11:07 by emamenko         ###   ########.fr       */
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

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;

	list = 0;
	i = -1;
	while (++i < ac)
		ft_list_push_front(&list, av[i]);
	return (list);
}
