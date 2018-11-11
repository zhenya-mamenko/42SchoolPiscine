/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:04:57 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/10 17:30:38 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		char_index(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i += 1;
	}
	return (c == '\0' ? i : -1);
}

int		char_index2(char *chars, char *str)
{
	int i;
	int j;
	int result;

	result = -1;
	j = 0;
	while (chars[j])
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == chars[j])
			{
				if (result == -1 || result > i)
					result = i;
				break ;
			}
			i += 1;
		}
		j += 1;
	}
	return (result);
}
