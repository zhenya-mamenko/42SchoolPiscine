/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:23:29 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/08 21:25:35 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int		error(int e, char *name, int use_name)
{
	ft_putstr("ft_tail: ");
	if (use_name == 1)
	{
		ft_putstr(name);
		ft_putstr(": ");
	}
	if (errno == ENOENT)
		e = 3;
	ft_putstr(g_errors[e - 1]);
	if (use_name == 2)
	{
		ft_putstr(name);
		ft_putchar('\n');
	}
	return (e);
}

void	ft_puthex(int nb, char *lead)
{
	long	n;
	int		i;
	int		l;

	i = 1;
	l = 16;
	n = nb;
	if (n < 0)
		n = 256 + n;
	nb = n;
	while (n > l - 1)
	{
		n = n / l;
		i = i * l;
		lead += 1;
	}
	ft_putstr(lead + 1);
	while (i > 0)
	{
		ft_putchar(g_base[(nb / i)]);
		nb = nb % i;
		i = i / l;
	}
}
