/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:50:06 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/08 20:30:23 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "common.h"

int		rfile(char *name, int output, int pos)
{
	int		cnt;
	int		f;
	char	*a;

	if (ft_strcmp(name, "-") == 0)
		f = 0;
	else
		f = open(name, O_RDONLY);
	if (f == -1)
		return (error(1, name, 1));
	if (pos != 0 && lseek(f, pos, pos > 0 ? SEEK_SET : SEEK_END) == -1)
		return (error(7, name, 1));
	a = malloc(sizeof(char) * BUF);
	while ((cnt = read(f, a, BUF - 1)))
	{
		a[cnt] = '\0';
		ft_putstr_file(a, output);
	}
	free(a);
	if (f != 0 && close(f) == -1)
		return (error(2, name, 1));
	return (0);
}

int		check_valid(char *str, char *valid)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
		j = 0;
		while (valid[j])
		{
			if (str[i] == valid[j])
				break ;
			j += 1;
			if (!valid[j])
				return (1);
		}
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			c = 1;
		i += 1;
	}
	return (c);
}

int		check_argv(int *pac, char **av, int *output, int *p)
{
	int		ac;
	char	*n;

	ac = *pac;
	if ((ac > 2 && av[ac - 1][0] == '>') ||
		(ac > 3 && ft_strcmp(av[ac - 2], ">") == 0))
	{
		n = (ac > 2 && av[--ac][0] == '>') ? &av[ac][1] : av[ac--];
		*output = open(n, O_WRONLY | O_CREAT | O_TRUNC);
		if (*output == -1)
			return (error(1, n, 1));
	}
	if (ac > 2 && ft_strcmp(av[1], "-c") == 0)
	{
		if (ac == 3)
			return (error(5, "", 0));
		if (ac == 2)
			return (error(6, "", 0));
		if (check_valid(av[2], "+-0123456789"))
			return (error(4, av[2], 2));
		*p = ft_atoi_tail(av[2]);
	}
	*pac = ac;
	return (0);
}

int		sfname(char *name, int *c)
{
	if (*c != 1)
		ft_putchar('\n');
	ft_putstr("==> ");
	ft_putstr(name);
	ft_putstr(" <==\n");
	*c = 2;
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		output;
	int		pos;
	int		c;

	if (ac == 1)
		return (error(5, "", 0));
	else
	{
		output = 1;
		pos = 0;
		if (check_argv(&ac, av, &output, &pos) != 0)
			return (1);
		if (ft_strcmp(av[1], "-c") == 0 && pos == 0)
			return (0);
		i = pos != 0 ? 2 : 0;
		c = ac - i > 2 ? 1 : 0;
		while (++i < ac)
		{
			if ((c && sfname(av[i], &c)) || rfile(av[i], output, pos))
				return (1);
		}
		if (output != 1 && close(output) == -1)
			return (error(2, av[i], 1));
	}
}
