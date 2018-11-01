/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:35:17 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 14:44:09 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int c;
	int l;

	l = 0;
	while (to_find[l])
		l += 1;
	if (l == 0)
		return (str);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (c < l && str[i] == to_find[c])
		{
			c += 1;
			if (c == l)
				return (str + i - c + 1);
		}
		else
			c = 0;
		i += 1;
	}
	return ((void*)0);
}
