/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:08:40 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/05 19:31:19 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	main(int ac, char **av)
{
	int		i;
	long	value1;
	long	value2;

	if (ac != 4)
		return (1);
	i = -1;
	while (++i < 5)
	{
		if (av[2][0] == g_op[i].op)
		{
			value1 = ft_atoi(av[1]);
			value2 = ft_atoi(av[3]);
			if (value2 == 0 && (g_op[i].op == '/' || g_op[i].op == '%'))
			{
				ft_putstr(g_op[i].error);
				return (1);
			}
			ft_putnbr(g_op[i].func(value1, value2));
			ft_putchar('\n');
			return (0);
		}
	}
	ft_putstr("0\n");
	return (1);
}
