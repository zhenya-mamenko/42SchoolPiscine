/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:53:11 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/08 23:38:30 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		is_same(char *b1, char *b2)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (b1[i] != b2[i])
			return (0);
		i += 1;
	}
	return (1);
}

int	print_buf(char *b, int l, int (*f)(char*, int, int), int flush)
{
	int i;
	int sl;
	int r;

	if (flush)
		return (f(g_cbuf, g_buf_size, g_address));
	r = 0;
	i = 0;
	while (i < l)
	{
		sl = l - i > 16 ? 16 : l - i;
		ft_strncpy(g_cbuf + g_buf_size, b + i, sl - g_buf_size);
		if (sl != 16)
		{
			g_buf_size = sl;
			g_address += i;
			return (0);
		}
		if (i == 0 || !is_same(g_cbuf, g_pbuf))
		{
			f(g_cbuf, sl, i + g_address);
			r = 0;
		}
		else if (r != 1)
		{
			ft_putstr("*\n");
			r = 1;
		}
		ft_strncpy(g_pbuf, b + i, sl);
		i += 16 - g_buf_size;
		g_address += g_buf_size;
		g_buf_size = 0;
	}
	return (0);
}

int	print_hex(char *b, int l, int a)
{
	int i;

	ft_puthex(a, "0000000");
	i = 0;
	while (i < l)
	{
		ft_putchar(' ');
		ft_puthex(b[i], "00");
		i += 1;
	}
	while (i++ < 16)
		ft_putstr("   ");
	ft_putchar('\n');
	if (l != 16)
	{
		ft_puthex(a + l, "0000000");
		ft_putchar('\n');
	}
	return (0);
}

void	print_symbols(char *b, int l)
{
	int i;

	i = 0;
	ft_putstr("  |");
	while (i < l)
	{
		ft_putchar(b[i] >= ' ' ? b[i] : '.');
		i += 1;
	}
	ft_putstr("|\n");
}

int	print_hex_symb(char *b, int l, int a)
{
	int i;

	ft_puthex(a, "00000000");
	ft_putchar(' ');
	i = -1;
	while (++i < l)
	{
		ft_putchar(' ');
		ft_puthex(b[i], "00");
		if (i == 7)
			ft_putchar(' ');
	}
	while (i++ < 16)
	{
		if (i == 8)
			ft_putchar(' ');
		ft_putstr("   ");
	}
	print_symbols(b, l);
	if (l != 16)
	{
		ft_puthex(a + l, "00000000");
		ft_putchar('\n');
	}
	return (0);
}
