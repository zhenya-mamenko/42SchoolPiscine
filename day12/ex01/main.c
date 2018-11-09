/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:50:06 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/07 17:13:57 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "common.h"

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

int		read_file(char *name, int output)
{
	int		cnt;
	int		f;
	char	a[BUF];

	if (ft_strcmp(name, "-") == 0)
		f = 0;
	else
		f = open(name, O_RDONLY);
	if (f == -1)
		return (error(1, name));
	while ((cnt = read(f, a, BUF - 1)))
	{
		a[cnt] = '\0';
		ft_putstr_file(a, output);
	}
	if (f != 0 && close(f) == -1)
		return (error(2, name));
	return (0);
}

int		check_argv(int *pac, char **av, int *output)
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
			return (error(1, n));
	}
	*pac = ac;
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		output;

	if (ac == 1)
		read_file("-", 1);
	else
	{
		output = 1;
		if (check_argv(&ac, av, &output) != 0)
			return (1);
		i = 0;
		while (++i < ac)
			if (read_file(av[i], output) != 0)
				return (1);
		if (output != 1 && close(output) == -1)
			return (error(2, av[i]));
	}
}
