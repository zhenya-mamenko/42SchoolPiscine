/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:50:06 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/08 23:12:57 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		read_files(int ac, int *st, char **av, int minus_c)
{
	int		cnt;
	int		f;
	char	*a;
	char	*name;

	a = malloc(sizeof(char) * BUF);
	while (++(*st) < ac)
	{
		name = (av != 0) ? av[*st] : (char*)0;
		if (name == 0)
			f = 0;
		else
			f = open(name, O_RDONLY);
		if (f == -1)
			return (error(1, name, 1));
		while ((cnt = read(f, a, BUF)))
			print_buf(a, cnt, minus_c == 1 ? &print_hex_symb : &print_hex, 0);
		if (f != 0 && close(f) == -1)
			return (error(2, name, 1));
	}
	if (g_buf_size != 0)
		print_buf(0, 0, minus_c == 1 ? &print_hex_symb : &print_hex, 1);
	free(a);
	return (0);
}

int		check_argv(int *pac, char **av)
{
	int			ac;
	char		*n;

	ac = *pac;
	if ((ac > 2 && av[ac - 1][0] == '>') ||
		(ac > 3 && ft_strcmp(av[ac - 2], ">") == 0))
	{
		n = (ac > 2 && av[--ac][0] == '>') ? &av[ac][1] : av[ac--];
		g_output = open(n, O_WRONLY | O_CREAT | O_TRUNC);
		if (g_output == -1)
			return (error(1, n, 1));
	}
	*pac = ac;
	return (0);
}

int		main(int ac, char **av)
{
	int			i;

	g_output = 1;
	i = -1;
	if (ac == 1)
		return (read_files(1, &i, 0, 0));
	else
	{
		if (check_argv(&ac, av) != 0)
			return (1);
		g_address = 0;
		g_buf_size = 0;
		i = (ft_strcmp(av[1], "-C") == 0) ? 1 : 0;
		read_files(ac, &i, av, i);
		if (g_output != 1 && close(g_output) == -1)
			return (error(2, av[i], 1));
	}
}
