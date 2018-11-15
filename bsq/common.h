/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:58:03 by mkryukov          #+#    #+#             */
/*   Updated: 2018/11/12 15:52:52 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_cell
{
	char		value;
	int			size;
}				t_cell;

static char		*g_errors[] =
{
	"map error\n"
};

int				g_size_y;
int				g_size_x;
char			g_symbols[4];
t_cell			*g_map;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_atoi(const char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				error(int e);
int				char_index(char c, char *str);
int				check_params(char *params, int *size_y, char *symbols);
int				check_map(char *s);
void			calc_map(t_cell *map);
void			fill_map(t_cell *map);
void			print_map(t_cell *map);

#endif
