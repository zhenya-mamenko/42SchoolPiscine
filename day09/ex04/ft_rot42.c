/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:43:40 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/01 22:38:55 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A' + 42) % 26 + 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a' + 42) % 26 + 'a';
		i += 1;
	}
	return (str);
}
