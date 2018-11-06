/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:43:30 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/01 19:24:29 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		nhour;
	char	h;
	char	n;

	if (hour == 24)
		hour = 0;
	nhour = hour + 1;
	if (nhour >= 24)
		nhour -= 24;
	h = hour < 12 ? 'A' : 'P';
	n = nhour < 12 ? 'A' : 'P';
	if (hour == 0)
		hour = 12;
	if (nhour == 0)
		nhour = 12;
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M. AND %d.00 %c.M.\n",
		hour > 12 ? hour - 12 : hour, h,
		nhour > 12 ? nhour - 12 : nhour, n);
}
