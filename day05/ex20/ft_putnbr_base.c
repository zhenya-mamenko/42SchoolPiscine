/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:52:51 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 22:44:04 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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

void	putnbase(int nb, char *base, int l)
{
	long	n;
	long	n2;
	int		i;

	i = 1;
	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	n2 = n;
	while (n > l - 1)
	{
		n = n / l;
		i = i * l;
	}
	while (i > 0)
	{
		ft_putchar(base[(n2 / i)]);
		n2 = n2 % i;
		i = i / l;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	char	invalid[10];
	char	f[2];

	ft_strcpy(invalid, "+-\0");
	ft_strcpy(f, " \0");
	b = 0;
	while (base[b])
	{
		f[0] = base[b];
		if (ft_strstr(invalid, f) || ft_strstr(base + b + 1, f))
			return ;
		b += 1;
	}
	if (b < 2)
		return ;
	putnbase(nbr, base, b);
}
