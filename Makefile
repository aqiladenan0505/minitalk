# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadenan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 17:45:02 by aadenan           #+#    #+#              #
#    Updated: 2023/12/29 14:19:09 by aadenan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM := rm -rf

RED = \033[1;31m
GREEN = \033[1;32m
RESET = \033[0m

SERVER := server
CLIENT := client

SV_SRCS := server.c
SV_OBJS := $(SV_SRCS:.c=.o)

CLIENT_SRCS := client.c
CLIENT_OBJS := $(CLIENT_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)
	@echo "$(GREEN)--- Programs created ---$(RESET)"
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SV_OBJS) $(CLIENT_OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)
	@echo "$(RED)--- Programs removed ---$(RESET)"

re: fclean all

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER): $(SV_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT)
