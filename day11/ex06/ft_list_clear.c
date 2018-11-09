/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:50:54 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 10:56:38 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*t;

	if (*begin_list != 0)
	{
		t = (*begin_list);
		while (t != 0)
		{
			*begin_list = t;
			t = t->next;
			free(*begin_list);
			*begin_list = 0;
		}
	}
}
