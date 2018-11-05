/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:07:24 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/04 18:07:13 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

void	putnbr(int nb)
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

void	ft_show_tab(struct s_stock_par *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		putstr(par[i].str);
		ft_putchar('\n');
		putnbr(par[i].size_param);
		ft_putchar('\n');
		while (*par[i].tab)
		{
			putstr(*(par[i].tab++));
			ft_putchar('\n');
		}
		i += 1;
	}
}
