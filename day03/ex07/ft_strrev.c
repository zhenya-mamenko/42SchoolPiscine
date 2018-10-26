/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:16:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/25 13:16:35 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	int		l;
	char	tmp;

	i = 0;
	l = 0;
	while (str[l])
	{
		l++;
	}
	if (l > 1)
	{
		while (l > i + 1)
		{
			l--;
			tmp = str[l];
			str[l] = str[i];
			str[i++] = tmp;
		}
	}
	return (str);
}
