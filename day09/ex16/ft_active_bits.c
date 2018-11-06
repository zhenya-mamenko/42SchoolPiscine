/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:01:55 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 12:05:10 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int	v;
	unsigned int	i;
	unsigned int	count;

	v = (unsigned int)value;
	i = 2147483648;
	count = 0;
	while (i > 0)
	{
		count += (v & i) > 0 ? 1 : 0;
		i /= 2;
	}
	return (count);
}
