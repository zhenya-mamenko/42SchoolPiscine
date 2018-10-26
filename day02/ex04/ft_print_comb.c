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

void	ft_print_comb(void)
{
	char d1;
	char d2;
	char d3;

	d1 = '0' - 1;
	while (++d1 <= '7')
	{
		d2 = d1;
		while (++d2 <= '8')
		{
			d3 = d2;
			while (++d3 <= '9')
			{
				ft_putchar(d1);
				ft_putchar(d2);
				ft_putchar(d3);
				if (!(d1 == '7' && d2 == '8' && d3 == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
