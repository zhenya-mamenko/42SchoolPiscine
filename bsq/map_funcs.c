/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:58:03 by mkryukov          #+#    #+#             */
/*   Updated: 2018/11/12 15:24:37 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		check_params(char *params, int *size_y, char *symbols)
{
	int i;
	int j;
	int len;

	len = ft_strlen(params);
	if (len < 4 || params[len - 1] == params[len - 2] ||
		params[len - 1] == params[len - 3] ||
		params[len - 2] == params[len - 3])
	{
		free(params);
		return (0);
	}
	j = 2;
	i = len - 1;
	while (i >= len - 3)
	{
		symbols[j] = params[i];
		j--;
		i--;
	}
	symbols[3] = '\0';
	params[len - 3] = '\0';
	*size_y = ft_atoi(params);
	free(params);
	return ((*size_y < 1) ? 0 : 1);
}

int		check_map_sym_count(char *str)
{
	int i;
	int count;
	int ncount;

	i = 0;
	count = 0;
	ncount = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			ncount++;
			if (count != g_size_x)
				return (0);
			else
				count = -1;
		}
		count++;
		i++;
	}
	if (ncount != g_size_y)
		return (0);
	return (1);
}

int		check_map(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '\n' && (char_index(str[i], g_symbols) == -1 ||
			str[i] == g_symbols[2]))
		{
			free(str);
			return (0);
		}
		count++;
		i++;
	}
	i = check_map_sym_count(str);
	free(str);
	return (i);
}

void	fill_map(t_cell *map)
{
	int i;
	int j;
	int max;
	int x;

	i = -1;
	max = 0;
	while (++i < g_size_x * g_size_y)
		if (map[i].size > max)
		{
			max = map[i].size;
			x = i;
		}
	if (max == 0)
		return ;
	i = -1;
	while (++i < map[x].size)
	{
		j = -1;
		while (++j < map[x].size)
		{
			max = (x / g_size_x + i) * g_size_x + x % g_size_x + j;
			map[max].value = g_symbols[2];
		}
	}
}

void	print_map(t_cell *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_size_y)
	{
		j = 0;
		while (j < g_size_x)
		{
			ft_putchar(map[i * g_size_x + j].value);
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}
