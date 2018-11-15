# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 09:58:03 by mkryukov          #+#    #+#              #
#    Updated: 2018/11/14 19:48:43 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = main.c funcs.c map_funcs.c char_index.c calc_map.c ft_atoi.c
FLAGS = -Wall -Wextra -Werror

.PHONY: $(NAME) all clean fclean

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRCS)

clean:
	@echo "noop"

fclean:
	/bin/rm -f $(NAME)
