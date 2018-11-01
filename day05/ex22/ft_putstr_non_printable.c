/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:07:07 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/30 11:05:07 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int i;
	int d;
	int d1;

	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] < 127)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			d = str[i] >= 0 ? str[i] : 256 + str[i];
			d1 = d / 16;
			ft_putchar(d1 < 10 ? d1 + '0' : (d1 - 10) + 'a');
			d = d % 16;
			ft_putchar(d < 10 ? d + '0' : (d - 10) + 'a');
		}
		i += 1;
	}
}
