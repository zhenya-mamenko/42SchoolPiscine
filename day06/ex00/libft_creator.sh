# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 13:47:05 by emamenko          #+#    #+#              #
#    Updated: 2018/11/01 10:42:19 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_swap.c
ar rc libft.a ft_putchar.o ft_putstr.o ft_strlen.o ft_strcmp.o ft_swap.o
ranlib libft.a
