/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:47:53 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 14:49:55 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_perso.h"
#include "ft_fight.h"

void	print(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i += 1;
	}
}

void	ft_fight(t_perso *who, t_perso *whom, t_kicks what)
{
	if (who->life <= 0 && whom->life <= 0)
		return ;
	print(who->name);
	print(" does a ");
	print(what.name);
	print(" on ");
	print(whom->name);
	print(".\n");
	whom->life -= what.points;
	if (whom->life <= 0)
	{
		print(whom->name);
		print(" is dead.\n");
	}
}
