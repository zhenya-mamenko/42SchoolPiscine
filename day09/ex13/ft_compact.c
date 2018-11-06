/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 05:24:24 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 05:42:51 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		while (tab[i] == (char*)0 && i < length)
		{
			j = i + 1;
			while (j < length)
			{
				tab[j - 1] = tab[j];
				j += 1;
			}
			length -= 1;
		}
		i += 1;
	}
	return (length);
}
