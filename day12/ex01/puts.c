/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:23:29 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/07 16:23:36 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
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

int		error(int e, char *name)
{
	ft_putstr("ft_cat: ");
	ft_putstr(name);
	ft_putstr(": ");
	if (errno == ENOENT)
		e = 3;
	ft_putstr(g_errors[e - 1]);
	return (e);
}

void	ft_putstr_file(char *str, int output)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(output, (str + i), 1);
		i += 1;
	}
}
