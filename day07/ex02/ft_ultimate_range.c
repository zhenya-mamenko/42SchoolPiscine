/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:58:11 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/31 14:05:48 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*p;

	if (min >= max)
	{
		*range = (void*)0;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	p = *range;
	i = 0;
	while (min + i < max)
	{
		p[i] = min + i;
		i += 1;
	}
	return (max - min);
}
