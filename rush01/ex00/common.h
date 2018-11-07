/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:19:48 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/04 10:04:56 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_cell
{
	char			value;
	unsigned char	cand[10];
}				t_cell;

int				error(void);
void			print_board(t_cell *board);
void			print_cell_candidates(t_cell cell);
void			set_candidates(t_cell *board);
int				bi_col(int index, int col);
int				bi_row(int index, int row);
int				bi_sq(int index, int pos);
int				check_board(t_cell *board);
void			copy_board(t_cell *dest, t_cell *src);

#endif
