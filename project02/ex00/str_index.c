/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:30:04 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/10 18:12:24 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

int		str_index(char *to_find, char *str, int max_l)
{
	int i;
	int c;
	int l;

	l = 0;
	l = len(to_find);
	if (l == 0)
		return (0);
	i = -1;
	c = 0;
	max_l = (max_l == -1) ? len(str) : max_l;
	while (str[++i] && i < max_l)
		if (c < l && str[i] == to_find[c])
		{
			c += 1;
			if (c == l)
				return (i - c + 1);
		}
		else
		{
			i -= c;
			c = 0;
		}
	return (-1);
}

int		str_index2(char **to_find, char *str, int l)
{
	int j;
	int result;
	int pos;

	result = -1;
	l = l == -1 ? len(str) : l;
	j = 0;
	while (to_find[j])
	{
		if ((pos = str_index(to_find[j], str, l)) != -1)
		{
			if (result == -1 || result > pos)
				result = pos;
		}
		j += 1;
	}
	return (result);
}

int		str_index_rev(char *to_find, char *str, int max_l)
{
	int i;
	int c;
	int l;

	l = len(to_find);
	if (l == 0)
		return (0);
	i = max_l;
	c = l - 1;
	max_l = (max_l == -1) ? len(str) : max_l;
	while (str[--i] && i >= 0)
		if (c >= 0 && str[i] == to_find[c])
		{
			c -= 1;
			if (c == -1)
				return (i);
		}
		else
		{
			i += l - c - 1;
			c = l - 1;
		}
	return (-1);
}

int		str_index_rev2(char **to_find, char *str, int l)
{
	int j;
	int result;
	int pos;

	result = -1;
	l = l == -1 ? len(str) : l;
	j = 0;
	while (to_find[j])
	{
		if ((pos = str_index_rev(to_find[j], str, l)) != -1)
		{
			if (result < pos)
				result = pos;
		}
		j += 1;
	}
	return (result);
}
