# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 22:49:44 by hbenaddi          #+#    #+#              #
#    Updated: 2024/09/16 12:24:44 by hbenaddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude  -pthread -g3
NAME = philosopher
SRC_DIR = src
OBJ_DIR = obj
CMD_DIR = cmd

SRCS = $(SRC_DIR)/start_init.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/action.c \
			$(SRC_DIR)/creation.c \
			$(SRC_DIR)/time.c \
			$(SRC_DIR)/mod_atol.c \
			$(SRC_DIR)/main.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
