/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:28:31 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/08 23:22:06 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# define BUF 16384

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(long nb);
void		ft_puthex(int nb, char *lead);
int			error(int e, char *name, int use_name);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
int			print_buf(char *b, int l, int (*f)(char*, int, int), int flush);
int			print_hex(char *b, int l, int a);
int			print_hex_symb(char *b, int l, int a);

static char	*g_errors[] =
{
	"Error in open() file\n",
	"Error in close() file\n",
	"No such file or directory\n"
};
static char	*g_base = "0123456789abcdef";
char		g_cbuf[16];
char		g_pbuf[16];
int			g_buf_size;
int			g_address;
int			g_output;

#endif
