/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 00:42:03 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 01:29:06 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			flight(unsigned int n, int *result)
{
	if (n == 1)
		return ;
	*result += 1;
	if (n % 2 == 0)
		flight(n / 2, result);
	else
		flight(n * 3 + 1, result);
}

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	int		result;

	result = 0;
	flight(base, &result);
	return (result);
}
