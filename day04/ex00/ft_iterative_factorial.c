/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:04:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/26 10:16:01 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;
	int i;

	if (nb < 0)
	{
		return (0);
	}
	if (nb <= 1)
	{
		return (1);
	}
	result = 1;
	i = 2;
	while (i <= nb)
	{
		if (__INT32_MAX__ / i < result)
		{
			result = 0;
			break ;
		}
		else
			result *= i;
		i++;
	}
	return (result);
}
