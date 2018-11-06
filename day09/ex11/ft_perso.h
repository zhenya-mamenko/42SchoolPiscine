/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 04:45:16 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 14:56:35 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_THE_WORLD "Saver of the World!"

# include <stdlib.h>

char			*strdup(const char *src)
{
	char	*copy;
	int		i;
	int		l;

	l = 0;
	while (src[l])
		l += 1;
	copy = (char*)malloc(sizeof(char) * (l + 1));
	i = 0;
	while (i < l)
	{
		copy[i] = src[i];
		i += 1;
	}
	copy[l] = '\0';
	return (copy);
}

typedef struct	s_perso
{
	char	*name;
	float	life;
	int		age;
	char	*profession;
}				t_perso;

#endif
