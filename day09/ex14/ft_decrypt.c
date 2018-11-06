/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:30:42 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 13:19:42 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_perso.h"

void		slcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				l;

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
}

void		extract_perso(t_perso *p, char *str, int st, int en)
{
	char	*s;
	int		i;
	int		age;

	i = 0;
	while (str[st + i] != '|' && str[st + i])
		i += 1;
	s = malloc(sizeof(char) * (en - i));
	slcpy(s, str + st + i + 1, (en - i));
	p->name = s;
	en = st + i;
	age = 1;
	p->age = 0;
	while (st < en)
	{
		p->age = p->age * 10 + (str[st] - '0');
		st += 1;
	}
	p->life = 100.0;
	p->profession = SAVE_THE_WORLD;
}

t_perso		**ft_decrypt(char *str)
{
	t_perso		**p;
	int			i;
	int			j;
	int			count;

	count = 1;
	i = 0;
	while (str[i])
		count += str[i++] == ';' ? 1 : 0;
	p = malloc(sizeof(t_perso*) * (count + 1));
	p[count] = 0;
	i = -1;
	j = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ';')
		{
			extract_perso(p[count++] = malloc(sizeof(t_perso)), str, j, i);
			j = i + 1;
		}
	}
	if (i > 0)
		extract_perso(p[count] = malloc(sizeof(t_perso)), str, j, i);
	return (p);
}
