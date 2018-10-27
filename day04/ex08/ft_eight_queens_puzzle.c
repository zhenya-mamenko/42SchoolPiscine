/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:04:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/26 10:16:01 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_check(char board[8][8], int r, int c)
{
	int i;

	i = 1;
	while (i < 8)
	{
		if ((r - i >= 0 && c - i >= 0 && board[r - i][c - i] == 'Q') ||
			(r + i < 8 && c + i < 8 && board[r + i][c + i] == 'Q') ||
			(r - i >= 0 && c + i < 8 && board[r - i][c + i] == 'Q') ||
			(r + i < 8 && c - i >= 0 && board[r + i][c - i] == 'Q'))
			return (0);
		i += 1;
	}
	i = 0;
	while (i < 8)
	{
		if (board[i][c] == 'Q' && i != r)
			return (0);
		i += 1;
	}
	return (1);
}

void	ft_place_queen(char board[8][8], int *result, int nb)
{
	int		i;
	char	*p;

	p = (char*)board;
	i = 0;
	while (i < 8)
	{
		board[nb][i] = 'Q';
		if (ft_check_check(board, nb, i))
		{
			if (nb + 1 == 8)
			{
				*result += 1;
			}
			else
				ft_place_queen(board, result, nb + 1);
		}
		board[nb][i] = '_';
		i++;
	}
}

int		ft_eight_queens_puzzle(void)
{
	int		result;
	char	board[8][8];
	char	*p;
	int		i;

	result = 0;
	p = (char*)board;
	i = 0;
	while (i < 64)
	{
		*(p + i) = '_';
		i += 1;
	}
	ft_place_queen(board, &result, 0);
	return (result);
}
