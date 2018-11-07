/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:15:22 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/04 09:25:12 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		bi_col(int index, int col)
{
	return ((index / 9) * 9 + col);
}

int		bi_row(int index, int row)
{
	return ((index % 9) + 9 * row);
}

int		bi_sq(int index, int pos)
{
	int i;

	i = (index / 27) * 27 + ((index % 9) / 3) * 3 +
		pos % 3 + (pos / 3) * 9;
	return (i);
}

int		check_board(t_cell *board)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (i < 81)
	{
		c += (board[i].value == '.' ? 1 : 0);
		i += 1;
	}
	return (c);
}

void	copy_board(t_cell *dest, t_cell *src)
{
	int i;

	i = 0;
	while (i < 81)
	{
		dest[i] = src[i];
		i += 1;
	}
}
