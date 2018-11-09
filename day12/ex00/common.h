/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:28:31 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/07 14:00:30 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# define BUF 16384

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(long nb);
int			error(int e);

static char	*g_errors[4] =
{
	"File name missing.\n",
	"Too many arguments.\n",
	"Error in open() file.\n",
	"Error in close() file.\n"
};

#endif
