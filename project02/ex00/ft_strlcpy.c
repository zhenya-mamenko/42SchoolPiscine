/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:23:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 17:47:49 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				l;

	i = 0;
	l = 0;
	while (src[l])
		l += 1;
	while (size != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i += 1;
		if (!src[i])
			break ;
	}
	if (size != 0)
		dest[i] = '\0';
	return (l);
}
