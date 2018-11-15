/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkryukov <mkryukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:03:14 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/13 23:20:37 by mkryukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		min(int a, int b)
{
	return (a > b ? b : a);
}

int		min_neighbors(t_cell *map, int x)
{
	int x1;
	int x2;
	int x3;
	int m;

	x1 = (x % g_size_x) + 1 == g_size_x ? -1 : x + 1;
	x2 = (x / g_size_x) + 1 == g_size_y ? -1 : x + g_size_x;
	x3 = x2 == -1 || x1 == -1 ? -1 : x + g_size_x + 1;
	m = min(x1 != -1 ? map[x1].size : 0, x2 != -1 ? map[x2].size : 0);
	m = min(x3 != -1 ? map[x3].size : 0, m);
	return (m);
}

void	calc_map(t_cell *map)
{
	int i;
	int len;

	len = g_size_x * g_size_y;
	i = -1;
	while (++i < len)
		map[i].size = 0;
	i = len;
	while (--i >= 0)
	{
		if (map[i].value == g_symbols[0])
			map[i].size = 1 + min_neighbors(map, i);
	}
	fill_map(map);
	print_map(map);
	free(g_map);
}
