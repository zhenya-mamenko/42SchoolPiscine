/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:58:03 by mkryukov          #+#    #+#             */
/*   Updated: 2018/11/13 21:52:41 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		read_params(int fd, char *str)
{
	char	*s;
	char	c;
	int		i;
	int		cnt;

	s = malloc(sizeof(char) * 16);
	i = 0;
	while ((cnt = read(fd, &c, 1)) == 1 && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	if (!check_params(s, &g_size_y, g_symbols))
	{
		free(str);
		return (0);
	}
	g_size_x = 0;
	while ((cnt = read(fd, &c, 1)) == 1 && c != '\n')
		str[g_size_x++] = c;
	str[g_size_x] = '\n';
	return (1);
}

int		read_data(int fd, char *s, int c, char *s1)
{
	int i;
	int cnt;
	int f;

	ft_strncpy(s, s1, g_size_x + 1);
	free(s1);
	f = 1;
	if (fd != 0)
	{
		if (c != 0 && !(read(fd, s + g_size_x + 1, c) == c
			&& read(fd, &i, 1) == 0))
			f = 0;
	}
	else
	{
		i = g_size_x + 1;
		cnt = 0;
		while (i <= c && (cnt += read(fd, s + i, g_size_x + 1)))
			i += g_size_x + 1;
		if (c == 0 || cnt != c)
			f = 0;
	}
	if (!f)
		free(s);
	return (f);
}

int		read_file(int fd)
{
	char	*s;
	char	*s1;
	int		i;
	int		j;
	int		c;

	if (!read_params(fd, (s1 = malloc(sizeof(char) * 1024))))
		return (error(1));
	g_map = malloc(sizeof(t_cell) * g_size_y * g_size_x);
	c = (g_size_y - 1) * (g_size_x + 1);
	s = malloc(sizeof(char) * g_size_y * (g_size_x + 1) + 1);
	if (!read_data(fd, s, c, s1))
		return (error(1));
	s[c + g_size_x + 1] = '\0';
	i = 0;
	j = -1;
	while (s[++j] && i < g_size_y * g_size_x)
		if (s[j] != '\n')
			g_map[i++].value = s[j];
	if (i == g_size_y * g_size_x)
		i = check_map(s);
	else
		i = 0;
	return (!i ? error(1) : 0);
}

int		main(int argc, char **argv)
{
	int i;
	int	fd;

	i = 0;
	if (argc < 2)
	{
		if (!read_file(0))
			calc_map(g_map);
	}
	else
		while (++i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				error(1);
			else if (!read_file(fd))
			{
				calc_map(g_map);
				if (close(fd) == -1)
					error(1);
			}
			ft_putstr((i != argc - 1) ? "\n" : "");
		}
	return (0);
}
