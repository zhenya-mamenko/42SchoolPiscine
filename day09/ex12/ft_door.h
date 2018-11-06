/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 05:00:43 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 14:52:34 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# define SUCCESS	0

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_state
{
	CLOSE,
	OPEN
}				t_state;

typedef struct	s_door
{
	t_state	state;
}				t_door;

void			ft_putstr(char *str);
t_bool			open_door(t_door *door);
t_bool			close_door(t_door *door);
t_bool			is_door_open(t_door *door);
t_bool			is_door_close(t_door *door);

#endif
