/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:13:17 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 12:19:09 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((i < n) && src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i += 1;
	}
	return (dest);
}
