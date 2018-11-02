/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:10:33 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/31 19:10:14 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int		index_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i += 1;
	}
	return (-1);
}

int		num_from_base(char *str, char *base, int l)
{
	int		result;
	int		f;
	int		negative;
	int		i;

	result = 0;
	f = -1;
	negative = 0;
	while (str[++f])
	{
		if (str[f] == '+' || str[f] == '-')
		{
			if (f != 0)
				return (0);
			negative = str[f] == '+' ? 1 : -1;
		}
		else
		{
			i = 0;
			while (base[i] != str[f])
				i += 1;
			result = result * l + i;
		}
	}
	return (result * (negative == 0 ? 1 : negative));
}

void	num_to_base(long n, char *base, char *c, int *r)
{
	int		l;

	l = 0;
	while (base[l])
		l += 1;
	if (n < 0)
	{
		c[*r] = '-';
		*r += 1;
		n = -n;
	}
	if (n >= l)
	{
		num_to_base(n / l, base, c, r);
		n = n % l;
	}
	if (n < l)
	{
		c[*r] = base[n];
		*r += 1;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*c;
	int		n;
	int		i;
	int		r;

	c = malloc(sizeof(char) * 34);
	i = 0;
	while (i < 35)
		c[i++] = '\0';
	c[0] = '0';
	if (!nbr[0])
		return (c);
	i = -1;
	while (nbr[++i])
		if (!(index_char(nbr[i], base_from) != -1 ||
			(i == 0 && (nbr[i] == '-' || nbr[i] == '+'))))
			return (c);
	i = 0;
	while (base_from[i])
		i += 1;
	n = num_from_base(nbr, base_from, i);
	r = 0;
	num_to_base(n, base_to, c, &r);
	return (c);
}
