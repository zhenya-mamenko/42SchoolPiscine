/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 02:28:28 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 03:45:44 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i += 1;
	}
}

char	*ss(char *str, char *to_find)
{
	int i;
	int c;
	int l;

	l = 0;
	while (to_find[l])
		l += 1;
	if (l == 0)
		return (str);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (c < l && str[i] == to_find[c])
		{
			c += 1;
			if (c == l)
				return (str + i - c + 1);
		}
		else
			c = 0;
		i += 1;
	}
	return ((void*)0);
}

int		is_empty(char *s, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i += 1;
	}
	return (1);
}

int		check(char *a, char *w)
{
	int		l;
	char	*p;
	int		l2;

	l = 0;
	while (w[l])
		l += 1;
	l2 = 0;
	while (a[l2])
		l2 += 1;
	p = ss(a, w);
	if (p && (p == a || *(p - 1) == ' ' || *(p - 1) == '\t') &&
		(*(p + l) == '\0' || *(p + l) == ' ' || *(p + l) == '\t'))
	{
		if (p != a)
			if (!is_empty(a, p - a))
				return (0);
		if (*(p + l) == '\0')
			if (!is_empty(p + l, a + l2 - p - l))
				return (0);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		result;
	int		i;
	int		j;

	result = 0;
	i = 1;
	while (i < ac && !result)
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] >= 'A' && av[i][j] <= 'Z')
				av[i][j] += ('a' - 'A');
		result = check(av[i], "president");
		if (!result)
		{
			result = check(av[i], "attack");
			if (!result)
				result = check(av[i], "bauer");
		}
		i += 1;
	}
	if (result)
		print("Alert!!!\n");
	return (result);
}
