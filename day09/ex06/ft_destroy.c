/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:42:32 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 00:27:06 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	char	**p;
	int		i;

	p = *factory;
	if (!p)
		return ;
	i = 0;
	while (p[i])
	{
		free(p[i]);
		i += 1;
	}
	free(p);
}
