# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 09:13:00 by emamenko          #+#    #+#              #
#    Updated: 2018/11/08 22:13:48 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump
SOURCES = main.c puts.c ft_strcmp.c ft_strncpy.c print.c

.PHONY: $(NAME) all clean fclean

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SOURCES)

clean:
	rm -f $(NAME)

fclean: clean
