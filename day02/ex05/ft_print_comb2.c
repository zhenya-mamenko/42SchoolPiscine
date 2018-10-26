/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:43:26 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/24 19:43:26 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int d1;
	int d2;

	d1 = -1;
	while (++d1 <= 98)
	{
		d2 = d1;
		while (++d2 <= 99)
		{
			ft_putchar((d1 / 10) + '0');
			ft_putchar((d1 % 10) + '0');
			ft_putchar(' ');
			ft_putchar((d2 / 10) + '0');
			ft_putchar((d2 % 10) + '0');
			if (!(d1 == 98 && d2 == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
