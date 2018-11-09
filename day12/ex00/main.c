/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:50:06 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/07 13:55:58 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "common.h"

int	main(int ac, char **av)
{
	char	a[BUF];
	int		f;
	int		cnt;

	if (ac == 1)
		return (error(1));
	if (ac > 2)
		return (error(2));
	f = open(av[1], O_RDONLY);
	if (f == -1)
		return (error(3));
	while ((cnt = read(f, a, BUF - 1)))
	{
		a[cnt] = '\0';
		ft_putstr(a);
	}
	if (close(f) == -1)
		return (error(4));
}
