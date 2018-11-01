/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:53:31 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 17:17:00 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	c;
	unsigned int	ld;
	unsigned int	ls;

	i = 0;
	c = 0;
	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	while (size != 0 && i < size - 1)
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
	if (size != 0 && size >= ld)
		dest[i] = '\0';
	return (size < ld ? size + ls : ld + ls);
}
