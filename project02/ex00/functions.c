/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:09:48 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/10 16:57:15 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

char	*clear_spaces(char *str)
{
	char	*s;
	int		i;
	int		j;

	s = malloc(sizeof(char) * (len(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			s[j] = str[i];
			j += 1;
		}
		i += 1;
	}
	s[j] = '\0';
	return (s);
}

void	ft_itoa(long nb, char *s, int *index)
{
	if (nb < 0)
	{
		s[(*index)++] = '-';
		ft_itoa(-nb, s, index);
	}
	else if (nb > 9)
	{
		ft_itoa(nb / 10, s, index);
		ft_itoa(nb % 10, s, index);
	}
	else
	{
		s[(*index)++] = nb + '0';
	}
	s[*index] = '\0';
}
