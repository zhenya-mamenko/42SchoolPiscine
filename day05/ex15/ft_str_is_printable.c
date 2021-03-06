/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:17:11 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/29 22:00:19 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] >= 127)
		{
			return (0);
		}
		i += 1;
	}
	return (1);
}
