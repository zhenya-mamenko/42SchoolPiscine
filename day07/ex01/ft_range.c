/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:25:07 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/31 16:11:44 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *a;

	if (min >= max)
		return ((void*)0);
	a = malloc(sizeof(int) * (max - min));
	i = 0;
	while (min + i < max)
	{
		a[i] = min + i;
		i += 1;
	}
	return (a);
}
