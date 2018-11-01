/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:28:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/30 10:01:53 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (!src[i])
			break ;
		i += 1;
	}
	return (dest);
}

char	*ft_strstr(char *str, char *to_find)
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

int		atoi_from_base(char *str, char *base, int l)
{
	int		result;
	int		s;
	int		f;
	int		negative;

	result = 0;
	s = 0;
	f = 0;
	negative = 0;
	while (str[f])
	{
		if (str[f] == '+' || str[f] == '-')
		{
			if (f != 0)
				return (0);
			negative = str[f] == '+' ? 1 : -1;
		}
		else
		{
			result = result * l + index_char(str[f], base);
		}
		f += 1;
	}
	return (result * (negative == 0 ? 1 : negative));
}

int		ft_atoi_base(char *str, char *base)
{
	int		b;
	int		i;
	char	invalid[10];
	char	f[2];

	ft_strcpy(invalid, "+-\0");
	ft_strcpy(f, " \0");
	b = 0;
	while (base[b])
	{
		f[0] = base[b];
		if (ft_strstr(invalid, f) || ft_strstr(base + b + 1, f))
			return (0);
		b += 1;
	}
	if (b < 2 || !str[0])
		return (0);
	i = -1;
	while (str[++i])
	{
		f[0] = str[i];
		if (!ft_strstr(base, f) && !ft_strstr(invalid, f))
			return (0);
	}
	return (atoi_from_base(str, base, b));
}
