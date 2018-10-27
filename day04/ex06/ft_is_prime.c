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

int		ft_sqrt_near(int nb)
{
	int max;
	int i;

	if (nb == 0 || nb == 1)
	{
		return (nb);
	}
	max = nb / 2;
	i = 2;
	while (i <= max)
	{
		if (i * i >= nb)
			return (i);
		i += 1;
	}
	return (0);
}

int		ft_is_prime(int nb)
{
	int max;
	int i;

	if (nb <= 1)
	{
		return (0);
	}
	max = ft_sqrt_near(nb);
	i = 2;
	while (i <= max)
	{
		if (nb % i == 0)
			return (0);
		i += 1;
	}
	return (1);
}
