/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:21:56 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/04 10:06:02 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	check_candidates(int x, t_cell *cell, t_cell *board)
{
	int		j;
	char	c;

	j = -1;
	while (++j < 9)
		if (board[bi_col(x, j)].value != '.')
			cell->cand[board[bi_col(x, j)].value - '0'] = 0;
	j = -1;
	while (++j < 9)
		if (board[bi_row(x, j)].value != '.')
			cell->cand[board[bi_row(x, j)].value - '0'] = 0;
	j = -1;
	while (++j < 9)
	{
		c = board[bi_sq(x, j)].value;
		if (c != '.')
			cell->cand[c - '0'] = 0;
	}
}

int		count_hidden_candidates(int x, unsigned char cand, t_cell *b, int t)
{
	int c;
	int j;

	c = 0;
	j = -1;
	while (++j < 9)
	{
		if (t == 1)
			c += b[bi_col(x, j)].cand[cand];
		else if (t == 2)
			c += b[bi_row(x, j)].cand[cand];
		else if (t == 3)
			c += b[bi_sq(x, j)].cand[cand];
	}
	return (c);
}

int		check_hidden_one(int x, t_cell *cell, t_cell *board)
{
	int j;
	int i;
	int c;

	i = 0;
	c = 0;
	while (++i < 10)
	{
		if (!cell->cand[i])
			continue ;
		c = count_hidden_candidates(x, i, board, 1);
		if (c != 1)
			c = count_hidden_candidates(x, i, board, 2);
		if (c != 1)
			c = count_hidden_candidates(x, i, board, 3);
		if (c == 1)
		{
			cell->value = '0' + i;
			j = 0;
			while (++j < 10)
				cell->cand[j] = 0;
			break ;
		}
	}
	return (cell->value == '.' ? 0 : 1);
}

int		check_one(t_cell *cell)
{
	int i;
	int v;

	i = 1;
	v = 0;
	while (i < 10)
	{
		if (cell->cand[i] == 1)
		{
			if (v != 0)
				return (0);
			v = i;
		}
		i += 1;
	}
	if (v != 0)
	{
		cell->value = '0' + v;
		i = 0;
		while (++i < 10)
			cell->cand[i] = 0;
	}
	return (v);
}

void	set_candidates(t_cell *board)
{
	int i;
	int j;
	int c;

	j = 1;
	c = 0;
	while (j)
	{
		j = 0;
		i = -1;
		while (++i < 81)
			if (board[i].value == '.')
			{
				check_candidates(i, &board[i], board);
				j += check_hidden_one(i, &board[i], board);
				if (board[i].value == '.')
					j += check_one(&board[i]);
			}
	}
}
