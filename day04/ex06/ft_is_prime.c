/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:04:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/26 10:16:01 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_sqrt_near(int nb, int d)
{
	int i;

	if ((__INT32_MAX__ / d) < d || nb < (d * d))
		return (find_sqrt_near(nb, (d / 2)));
	i = d;
	while (1)
	{
		if (nb >= i * i)
			return (i);
		i += 1;
	}
}

int		ft_is_prime(int nb)
{
	int max;
	int i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	max = find_sqrt_near(nb, nb / 2) + 1;
	i = 2;
	while (i <= max)
	{
		if (nb % i == 0)
			return (0);
		i += 1;
	}
	return (1);
}
