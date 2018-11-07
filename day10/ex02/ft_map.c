/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 10:45:22 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/05 10:53:05 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *result;

	result = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i += 1;
	}
	return (result);
}
