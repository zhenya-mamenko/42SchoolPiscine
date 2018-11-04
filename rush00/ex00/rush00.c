/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 08:48:54 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/27 19:28:02 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x , int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == x - 1) ||
				(i == y - 1 && j == 0) || (i == y - 1 && j == x - 1))
			{
				ft_putchar('o');
			}
			else if ((i == 0) || (i == y - 1))
			{
				ft_putchar('-');
			}
			else if ((j == 0) || (j == x - 1))
			{
				ft_putchar('|');
			}
			else
			{
				ft_putchar(' ');
			}
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}
