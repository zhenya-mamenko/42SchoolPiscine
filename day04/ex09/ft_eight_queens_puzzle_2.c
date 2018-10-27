/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:04:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/26 10:16:01 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i += 1;
	}
}

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
		if (board[r][i] == 'Q' && i != c)
			return (0);
		i += 1;
	}
	return (1);
}

void	ft_place_queen(char board[8][8], char result[8], int nb)
{
	int		i;
	char	*p;

	p = (char*)board;
	i = 0;
	while (i < 8)
	{
		board[i][nb] = 'Q';
		if (ft_check_check(board, i, nb))
		{
			result[nb] = i + '1';
			if (nb + 1 == 8)
			{
				ft_putstr((char*)result);
				ft_putchar('\n');
			}
			else
				ft_place_queen(board, result, nb + 1);
		}
		board[i][nb] = '_';
		i += 1;
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	char	result[9];
	char	board[8][8];
	char	*p;
	int		i;

	p = (char*)board;
	i = 0;
	while (i < 8)
	{
		result[i] = ' ';
		i += 1;
	}
	result[8] = '\0';
	i = 0;
	while (i < 64)
	{
		*(p + i) = '_';
		i += 1;
	}
	ft_place_queen(board, result, 0);
}
