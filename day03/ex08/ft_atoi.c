/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:16:35 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/25 13:16:35 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		result;
	int		s;
	int		f;
	int		negative;

	result = 0;
	s = -1;
	f = 0;
	while (str[f])
	{
		if (str[f] >= '0' && str[f] <= '9')
		{
			s = s == -1 ? f : s;
		}
		else if (s != -1)
			break ;
		f++;
	}
	negative = (s > 0) && (str[s - 1] == '-') ? -1 : 1;
	while (s >= 0 && s < f)
	{
		result = result * 10 + (int)(str[s++] - 48);
	}
	return (result * negative);
}
