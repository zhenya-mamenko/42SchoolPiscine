/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:22:26 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/05 20:26:03 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

int				ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(long nb);
long			ft_add(long value1, long value2);
long			ft_sub(long value1, long value2);
long			ft_mul(long value1, long value2);
long			ft_div(long value1, long value2);
long			ft_mod(long value1, long value2);
long			ft_usage(long value1, long value2);

typedef struct	s_opp
{
	char	*op;
	long	(*func)(long, long);
}				t_opp;

#endif
