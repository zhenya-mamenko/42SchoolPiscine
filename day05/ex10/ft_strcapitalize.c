/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:03:30 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 16:08:40 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= '0' && str[i] <= '9'))
		{
			if (c == 0 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] -= ('a' - 'A');
			else if (c == 1 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += ('a' - 'A');
			c = 1;
		}
		else
			c = 0;
		i += 1;
	}
	return (str);
}
