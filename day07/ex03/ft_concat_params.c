/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:47:56 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/31 18:07:06 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		slen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i += 1;
	}
	return (i);
}

char	*scpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (!src[i])
			break ;
		i += 1;
	}
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		l;
	int		i;
	int		j;
	char	*c;

	i = 1;
	l = 0;
	while (i < argc)
	{
		l += slen(argv[i]) + 1;
		i += 1;
	}
	c = malloc(sizeof(char) * l);
	i = 1;
	j = 0;
	while (i < argc)
	{
		scpy(c + j, argv[i]);
		j += slen(argv[i]);
		c[j++] = '\n';
		i += 1;
	}
	c[j - 1] = '\0';
	return (c);
}
