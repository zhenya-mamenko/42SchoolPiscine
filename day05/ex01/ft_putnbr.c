/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 08:16:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 19:36:51 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long	n;
	long	n2;
	int		i;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = 1;
	n2 = n;
	while (n > 9)
	{
		n = n / 10;
		i = i * 10;
	}
	while (i > 0)
	{
		ft_putchar((n2 / i) + '0');
		n2 = n2 % i;
		i = i / 10;
	}
}
