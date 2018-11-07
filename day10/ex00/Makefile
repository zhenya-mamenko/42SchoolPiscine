# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 09:13:00 by emamenko          #+#    #+#              #
#    Updated: 2018/11/05 18:14:42 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS_DIR = srcs
H_DIR = includes
SOURCES = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_putstr.c \
		$(SRCS_DIR)/ft_strcmp.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_swap.c
OBJECTS = ft_putchar.o ft_putstr.o ft_strlen.o ft_strcmp.o ft_swap.o

.PHONY: $(NAME) all clean fclean re

all: $(NAME)

$(NAME):
	gcc -I$(H_DIR) -c $(SOURCES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
