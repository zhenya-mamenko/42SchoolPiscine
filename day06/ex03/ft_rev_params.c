/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:16:22 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/30 13:50:52 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

int		main(int argc, char **argv)
{
	while (argc-- > 1)
	{
		putstr(argv[argc]);
		ft_putchar('\n');
	}
	return (0);
}
