/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:02:51 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/31 19:55:58 by emamenko         ###   ########.fr       */
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

int		slcpy(char *dest, char *src, int size)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (src[l])
		l += 1;
	while (size != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i += 1;
		if (!src[i])
			break ;
	}
	if (size != 0)
		dest[i] = '\0';
	return (l);
}

int		index_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i += 1;
	}
	return (-1);
}

void	set_word(char *str, char **a, int w, int l)
{
	a[w] = malloc(sizeof(char) * l);
	slcpy(a[w], str, l);
}

char	**ft_split(char *str, char *charset)
{
	char	**a;
	int		l;
	int		i;
	int		w;

	w = 0;
	l = 0;
	a = malloc(sizeof(char*) * (slen(str) / 2 + 1));
	i = -1;
	while (str[++i])
	{
		if (index_char(str[i], charset) == -1)
			l += 1;
		else if (l != 0)
		{
			set_word(str + i - l, a, w++, l + 1);
			l = 0;
		}
	}
	if (l != 0)
		set_word(str + i - l, a, w++, l + 1);
	a[w != 0 ? w : 0] = 0;
	return (a);
}
