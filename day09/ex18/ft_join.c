/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:17:31 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 12:36:43 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		slen(char *s)
{
	int l;

	l = 0;
	while (s[l])
		l += 1;
	return (l);
}

void	scpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
}

char	*ft_join(char **tab, char *sep)
{
	int		i;
	int		len;
	char	*s;

	i = -1;
	len = 0;
	while (tab[++i])
		len += slen(tab[i]) + slen(sep);
	s = malloc(len > 0 ? len + 1 - slen(sep) : 1);
	s[len] = '\0';
	i = 0;
	len = 0;
	while (tab[i])
	{
		scpy(s + len, tab[i]);
		len += slen(tab[i]);
		i += 1;
		if (tab[i])
		{
			scpy(s + len, sep);
			len += slen(sep);
		}
	}
	return (s);
}
