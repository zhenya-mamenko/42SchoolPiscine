/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:36:41 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/30 10:30:28 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (1)
	{
		if (c > 0 || !dest[i])
		{
			dest[i] = src[c];
			if (!src[c])
				break ;
			c += 1;
		}
		i += 1;
	}
	return (dest);
}
