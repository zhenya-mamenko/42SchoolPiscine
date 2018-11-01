/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:16:22 by emamenko          #+#    #+#             */
/*   Updated: 2018/10/30 15:01:58 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		cmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	if (s1[i] == '\0')
	{
		if (s2[i] == '\0')
			return (0);
		else
			return (-s2[i]);
	}
	else
		return (s1[i]);
}

void	sort_args(int *pos, char **argv, int argc)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < argc)
	{
		pos[i] = i + 1;
		i += 1;
	}
	i = -1;
	while (++i < argc - 1)
	{
		j = i - 1;
		while (++j < argc)
		{
			if (cmp(argv[pos[i]], argv[pos[j]]) > 0)
			{
				tmp = pos[j];
				pos[j] = pos[i];
				pos[i] = tmp;
			}
		}
	}
}

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
	int i;
	int pos[1000];

	sort_args(pos, argv, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		putstr(argv[pos[i]]);
		ft_putchar('\n');
		i += 1;
	}
	return (0);
}
