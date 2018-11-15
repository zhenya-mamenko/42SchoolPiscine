/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 08:26:07 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/30 11:17:21 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		index_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i += 1;
	}
	return (-1);
}

int		testchar(char c, int *n, int *s, int *result)
{
	if (c == '+' || c == '-')
	{
		if (*n != 0 || *s == 1)
		{
			*s = 1;
			return (0);
		}
		*n = c == '+' ? 1 : -1;
		return (1);
	}
	else if (index_char(c, "\t\n\v\f\r \0") == -1)
	{
		*result = *result * 10 + (c - '0');
		*s = 1;
		return (1);
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int		result;
	int		s;
	int		f;
	int		negative;

	result = 0;
	s = 0;
	f = 0;
	negative = 0;
	while ((str[f] >= '0' && str[f] <= '9') || str[f] == '+' ||
		str[f] == '-' || index_char(str[f], "\t\n\v\f\r \0") != -1)
	{
		if (!testchar(str[f], &negative, &s, &result) && (s == 1))
			break ;
		f += 1;
	}
	return (result * (negative == 0 ? 1 : negative));
}
