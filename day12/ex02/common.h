/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:28:31 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/07 22:18:10 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# define BUF 16384

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(long nb);
int			error(int e, char *name, int use_name);
void		ft_putstr_file(char *str, int output);
int			ft_atoi_tail(char *str);
int			ft_strcmp(char *s1, char *s2);

static char	*g_errors[] =
{
	"Error in open() file\n",
	"Error in close() file\n",
	"No such file or directory\n",
	"illegal offset -- ",
	"Need at least one file as argument\n",
	"option requires an argument -- c\n",
	"Error in lseek() file\n"
};

#endif
