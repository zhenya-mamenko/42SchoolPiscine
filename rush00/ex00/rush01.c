/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 09:30:04 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/28 09:32:02 by emamenko         ###   ########.fr       */
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
			if (i == 0 && j == 0)
			{
				ft_putchar('/');
			} 
			else if (i == 0 && j == x - 1)
			{
				ft_putchar('\\');
			}
			else if (i == y - 1 && j == 0)
			{
				ft_putchar('\\');
			}
			else if (i == y - 1 && j == x - 1)
			{
				ft_putchar('/');
			}						
			else if ((i == 0) || (i == y - 1) || (j == 0) || (j == x - 1))
			{
				ft_putchar('*');
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
