# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadenan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:22:14 by aadenan           #+#    #+#              #
#    Updated: 2023/10/10 15:06:24 by aadenan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_printf.c ft_csdi.c ft_uptr.c ft_xX.c ft_atoi.c

RED = \033[1;31m
GREEN = \033[1;32m
RESET = \033[0m

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	@echo "$(GREEN)--- Library created ---$(RESET)"
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)--- Library removed ---$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re

all: $(NAME)

