/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:04:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/26 10:16:01 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int result;
	int i;

	if (power < 0 || nb == 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	result = nb;
	i = 2;
	while (i <= power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
