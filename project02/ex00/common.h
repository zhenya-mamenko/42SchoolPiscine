/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:47:57 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/10 17:31:37 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

typedef struct		s_op
{
	char			*op;
	int				(*func)(int, int);
}					t_op;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(long nb);
int					eval_expr(char *str);
int					ft_atoi(char *str);
int					ft_add(int value1, int value2);
int					ft_sub(int value1, int value2);
int					ft_mul(int value1, int value2);
int					ft_div(int value1, int value2);
int					ft_mod(int value1, int value2);
int					len(char *s);
int					char_index(char c, char *str);
int					char_index2(char *chars, char *str);
int					str_index(char *to_find, char *str, int max_l);
int					str_index2(char **to_find, char *str, int l);
int					str_index_rev(char *to_find, char *str, int max_l);
int					str_index_rev2(char **to_find, char *str, int l);
char				*clear_spaces(char *str);
void				ft_itoa(long nb, char *s, int *index);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

static t_op			g_op[5] =
{
	{" + ", &ft_add},
	{" - ", &ft_sub},
	{" * ", &ft_mul},
	{" / ", &ft_div},
	{" % ", &ft_mod}
};

#endif
