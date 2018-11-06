/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:50:22 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/02 13:11:39 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(int *tab, int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		while (tab[i] == 0 && i < length)
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

int		ft_unmatch(int *tab, int length)
{
	int		tmp;
	int		i;

	while (length > 1)
	{
		i = 1;
		while (i < length)
		{
			tmp = 1;
			if (tab[0] == tab[i])
			{
				tab[0] = 0;
				tab[i] = 0;
				length = ft_compact(tab, length);
				tmp = 0;
				break ;
			}
			i += 1;
		}
		if (tmp)
			break ;
	}
	return (tab[0]);
}
