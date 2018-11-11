# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 09:13:00 by emamenko          #+#    #+#              #
#    Updated: 2018/11/10 17:35:57 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SOURCES = main.c puts.c operations.c ft_atoi.c eval_expr.c ft_strlcpy.c \
	functions.c char_index.c str_index.c

.PHONY: $(NAME) all clean fclean

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SOURCES)

clean:
	@echo "noop"

fclean: clean
	rm -f $(NAME)
