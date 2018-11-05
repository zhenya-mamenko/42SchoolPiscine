/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:51:11 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/04 18:06:50 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int					sslen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		l;

	l = 0;
	while (src[l])
		l += 1;
	copy = malloc(sizeof(char) * (l + 1));
	i = 0;
	while (i < l)
	{
		copy[i] = src[i];
		i += 1;
	}
	copy[l] = '\0';
	return (copy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*p;

	p = malloc(sizeof(t_stock_par) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		p[i].size_param = sslen(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_strdup(av[i]);
		p[i].tab = ft_split_whitespaces(av[i]);
		i += 1;
	}
	p[i].str = 0;
	return (p);
}
