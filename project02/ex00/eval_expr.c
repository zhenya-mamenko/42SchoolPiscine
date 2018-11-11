/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:50:36 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/10 18:55:57 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

char	*g_op0[] = {" * ", " / ", " % ", " + ", " - ", 0};
char	*g_op1[] = {" * ", " / ", " % ", 0};
char	*g_op2[] = {" + ", " - ", 0};

int		eval_simple(char *str)
{
	int		i;
	int		result;
	int		pos;
	char	*s;

	s = malloc(sizeof(char) * (len(str) + 1));
	ft_strlcpy(s, str, len(str) + 1);
	result = 0;
	i = -1;
	while (++i < 5)
		if ((pos = str_index(g_op[i].op, s, -1)) != -1)
		{
			s[pos + 1] = '\0';
			result = g_op[i].func(ft_atoi(s), ft_atoi(s + pos + 2));
			break ;
		}
	free(s);
	return (result);
}

void	place_result(char *str, int result, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		str[i] = ' ';
		i += 1;
	}
	i = 0;
	ft_itoa(result, str, &i);
	str[char_index('\0', str)] = ' ';
}

void	eval_operations(char *str, int *result)
{
	int		i;
	int		j;
	char	*s;
	int		l;
	int		pos;

	l = len(str);
	s = malloc(sizeof(char) * (l + 1));
	ft_strlcpy(s, str, l + 1);
	pos = -1;
	i = str_index2(g_op1, s, -1);
	if (i == -1)
		i = str_index2(g_op2, s, -1);
	else if ((pos = str_index_rev2(g_op0, s, i - 1)) != -1)
		pos = pos + 2;
	j = str_index2(g_op0, s + i + 2, -1);
	j = (j == -1) ? l : j + i + 2;
	s[j] = '\0';
	*result = eval_simple(s + (pos == -1 ? 0 : pos));
	place_result(s + pos + 1, *result, j - pos);
	if (str_index2(g_op0, s, -1) != -1)
		eval_operations(s, result);
	free(s);
}

void	process_par(char *str, int *result)
{
	char	*s;
	int		i;
	int		j;

	s = malloc(sizeof(char) * (len(str) + 1));
	ft_strlcpy(s, str, len(str) + 1);
	while ((i = char_index('(', s) - 1) != -2)
	{
		while (s[++i])
			if (s[i] == '(')
			{
				j = i;
			}
			else if (s[i] == ')')
			{
				s[i] = '\0';
				eval_operations(s + j + 1, result);
				place_result(s + j, *result, i - j + 1);
				break ;
			}
	}
	eval_operations(s, result);
	free(s);
}

int		eval_expr(char *str)
{
	char	*s;
	int		i;
	int		result;

	i = 0;
	s = malloc(sizeof(char) * (len(str) + 1));
	ft_strlcpy(s, str, len(str) + 1);
	result = 0;
	process_par(s, &result);
	free(s);
	return (result);
}
