/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:55:15 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/01 18:42:05 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	print_tut(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		print(s[i]);
}

void	ft_generic(void)
{
	print_tut("Tut tut ; Tut tut\n");
}
