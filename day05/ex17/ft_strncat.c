/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:53:31 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/30 10:51:49 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (nb > 0)
	{
		if (c > 0 || !dest[i])
		{
			dest[i] = src[c];
			c += 1;
			if (!src[c] || c == nb)
			{
				dest[i + 1] = '\0';
				return (dest);
			}
		}
		i += 1;
	}
	return (dest);
}
