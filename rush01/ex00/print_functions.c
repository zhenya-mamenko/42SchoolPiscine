/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 17:29:05 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/04 09:24:29 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		error(void)
{
	write(1, &"Error\n", 6);
	return (1);
}

void	print_board(t_cell *board)
{
	int i;

	i = 0;
	while (i < 81)
	{
		write(1, &(board[i].value), 1);
		i += 1;
		if (i % 9 == 0)
			write(1, &"\n", 1);
		else
			write(1, &" ", 1);
	}
}

void	print_cell_candidates(t_cell cell)
{
	int		i;
	char	c;

	i = 1;
	while (i < 10)
	{
		c = (cell.cand[i] ? '0' + i : ' ');
		if (c != ' ')
			write(1, &c, 1);
		i += 1;
	}
	write(1, &"\t", 1);
}
