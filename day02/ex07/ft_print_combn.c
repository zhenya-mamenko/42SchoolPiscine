/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:43:26 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/26 00:26:27 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb, int l)
{
	while (l > 0)
	{
		ft_putchar((nb / l) + '0');
		nb = nb % l;
		l = l / 10;
	}
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i += 1;
	}
}

void	ft_print_combn(int n)
{
	int v[7];

	v[0] = 0;
	v[1] = 9;
	v[2] = 1;
	v[3] = 0;
	v[4] = 0;
	while (++v[0] < n && (v[2] *= 10) && (v[1] += v[2] * (9 - v[0])))
	{
		v[3] = v[3] * 10 + v[0];
		v[4] = v[4] * 10 + 1;
	}
	v[0] = v[3] - 1;
	while (++v[0] <= v[1])
	{
		ft_putnbr(v[0], v[2]);
		v[5] = v[4] * 10;
		while ((v[5] /= 10) > 0)
		{
			v[6] = (v[0] + v[5]) % 10;
			v[0] = v[6] == 0 ? v[3] + v[5] * 10 : v[0];
			v[3] = v[6] == 0 ? v[0] + 1 : v[3];
		}
		ft_putstr(v[0] != v[1] ? ", " : "");
	}
}
