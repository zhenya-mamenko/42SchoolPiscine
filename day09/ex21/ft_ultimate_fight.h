/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_fight.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:47:34 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/05 16:26:08 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ULTIMATE_FIGHT_H
# define FT_ULTIMATE_FIGHT_H
# define KICK		(t_kicks){"judo kick", 15.0}
# define PUNCH		(t_kicks){"judo punch", 5.0}
# define HEADBUTT	(t_kicks){"judo headbutt", 20.0}
# define KICK1		(t_kicks){"judo chop ichi", 13.0}
# define KICK2		(t_kicks){"judo chop ni", 3.0}
# define KICK3		(t_kicks){"judo chop san", 18.0}
# define KICK4		(t_kicks){"judo chop shi", 9.0}
# define KICK5		(t_kicks){"judo chop go", 11.0}
# define KICK6		(t_kicks){"judo chop roku", 13.0}
# define KICK7		(t_kicks){"judo chop shichi", 8.0}
# define KICK8		(t_kicks){"judo chop hachi", 6.0}
# define KICK9		(t_kicks){"judo chop ku", 11.0}
# define KICK10		(t_kicks){"judo chop ju", 9.0}
# define KICK11		(t_kicks){"judo chop hyaku", 18.0}
# define KICK12		(t_kicks){"judo chop sen", 10.0}

typedef struct	s_kicks
{
	char	*name;
	float	points;
}				t_kicks;

void			ft_ultimate_fight(t_perso *who, t_perso *whom, t_kicks what);

#endif
