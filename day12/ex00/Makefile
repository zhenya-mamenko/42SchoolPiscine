# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 09:13:00 by emamenko          #+#    #+#              #
#    Updated: 2018/11/07 13:54:09 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SOURCES = main.c puts.c

.PHONY: $(NAME) all clean fclean

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SOURCES)

clean:
	rm -f $(NAME)

fclean: clean
