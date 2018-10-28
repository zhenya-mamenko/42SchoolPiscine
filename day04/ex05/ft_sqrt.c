/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:04:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/26 10:16:01 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_sqrt(int nb, int d)
{
	int i;

	if ((__INT32_MAX__ / d) < d || nb < (d * d))
		return (find_sqrt(nb, (d / 2)));
	i = d;
	while (1)
	{
		if (nb == i * i)
			return (i);
		if (nb < i * i)
			return (0);
		i += 1;
	}
}

int		ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	return (find_sqrt(nb, (nb / 2)));
}
