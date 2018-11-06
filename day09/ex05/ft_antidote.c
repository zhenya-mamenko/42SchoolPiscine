/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:47:39 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/01 22:53:32 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	int tmp;

	if (i > j)
	{
		tmp = j > k ? j : k;
		tmp = tmp > i ? i : tmp;
	}
	else
	{
		tmp = i > k ? i : k;
		tmp = tmp > j ? j : tmp;
	}
	return (tmp);
}
