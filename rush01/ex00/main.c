/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:51:17 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/04 09:33:07 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	search(t_cell *board, int index, t_cell *b)
{
	int		i;
	int		j;

	b = malloc(sizeof(t_cell) * 81);
	copy_board(b, board);
	j = 0;
	while (++j < 10)
		if (b[index].cand[j] == 1)
		{
			b[index].value = '0' + j;
			set_candidates(b);
			if (!check_board(b))
			{
				copy_board(board, b);
				break ;
			}
			else
			{
				i = index;
				while (++i < 81)
					if (board[i].value == '.')
						search(board, i, 0);
			}
		}
	free(b);
}

void	start_recurse(t_cell *board)
{
	int i;

	i = 0;
	while (i < 81)
	{
		if (board[i].value == '.')
			break ;
		i += 1;
	}
	search(board, i, 0);
}

void	sudoku(t_cell *board)
{
	int i;
	int j;

	i = -1;
	while (++i < 81)
	{
		j = 0;
		while (++j < 10)
			board[i].cand[j] = board[i].value == '.' ? 1 : 0;
	}
	set_candidates(board);
	i = check_board(board);
	if (i)
		start_recurse(board);
	if (!check_board(board))
		print_board(board);
	else
		error();
}

int		main(int ac, char **av)
{
	t_cell	*board;
	int		i;
	int		j;

	if (ac != 10)
		return (error());
	board = malloc(sizeof(t_cell) * 81);
	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (!(av[i][j] == '.' || (av[i][j] >= '1' && av[i][j] <= '9')))
				return (error());
			board[(i - 1) * 9 + j].value = av[i][j];
			j += 1;
		}
		if (av[i][j] != '\0')
			return (error());
		i += 1;
	}
	sudoku(board);
	free(board);
}
