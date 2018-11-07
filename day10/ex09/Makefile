# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 09:13:00 by emamenko          #+#    #+#              #
#    Updated: 2018/11/05 19:56:12 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op
SOURCES = main.c operations.c ft_atoi.c puts.c

.PHONY: $(NAME) all clean

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SOURCES)

clean:
	rm -f $(NAME)
