/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:47:34 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 14:41:10 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIGHT_H
# define FT_FIGHT_H
# define KICK		(t_kicks){"judo kick", 15.0}
# define PUNCH		(t_kicks){"judo punch", 5.0}
# define HEADBUTT	(t_kicks){"judo headbutt", 20.0}

typedef struct	s_kicks
{
	char	*name;
	float	points;
}				t_kicks;

void			ft_fight(t_perso *who, t_perso *whom, t_kicks what);

#endif
