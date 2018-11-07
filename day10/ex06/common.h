/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:22:26 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/05 18:03:32 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

int				ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(long nb);
long			add(long value1, long value2);
long			substract(long value1, long value2);
long			multiply(long value1, long value2);
long			divide(long value1, long value2);
long			modulo(long value1, long value2);

typedef struct	s_op
{
	char	op;
	long	(*func)(long, long);
	char	*error;
}				t_op;

t_op	g_op[5] =
{
	{'+', &add, ""},
	{'-', &substract, ""},
	{'*', &multiply, ""},
	{'/', &divide, "Stop : division by zero\n"},
	{'%', &modulo, "Stop : modulo by zero\n"}
};

#endif
