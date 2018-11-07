/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:08:40 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/06 12:53:30 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_opp.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	if (s1[i] == '\0')
	{
		if (s2[i] == '\0')
			return (0);
		else
			return (-s2[i]);
	}
	else
		return (s1[i]);
}

int		check_error(long (*func)(long, long), long value)
{
	if (value == 0 && (func == &ft_div || func == &ft_mod))
	{
		if (func == &ft_div)
			ft_putstr("Stop : division by zero\n");
		else if (func == &ft_mod)
			ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

long	ft_usage(long value1, long value2)
{
	int i;

	ft_putstr("error : only [ ");
	i = 0;
	while (g_opptab[i].op[0] != '\0')
	{
		ft_putstr(g_opptab[i].op);
		ft_putchar(' ');
		i += 1;
	}
	ft_putstr("] are accepted.\n");
	return (value1 + value2);
}

int		main(int ac, char **av)
{
	int		i;
	long	value1;
	long	value2;

	if (ac != 4)
		return (1);
	i = -1;
	while (++i < 6)
	{
		if (ft_strcmp(av[2], g_opptab[i].op) == 0)
		{
			value1 = ft_atoi(av[1]);
			value2 = ft_atoi(av[3]);
			if (check_error(g_opptab[i].func, value2))
				return (1);
			ft_putnbr(g_opptab[i].func(value1, value2));
			ft_putchar('\n');
			return (0);
		}
	}
	ft_usage(0, 0);
	return (1);
}
