# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 22:49:44 by hbenaddi          #+#    #+#              #
#    Updated: 2024/09/15 22:49:45 by hbenaddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -pthread -g3
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
			$(SRC_DIR)/main.c \


OBJS = $(OBJ_DIR)/start_init.o \
			$(OBJ_DIR)/utils.o \
			$(OBJ_DIR)/time.o \
			$(OBJ_DIR)/action.o \
			$(OBJ_DIR)/creation.o \
			$(OBJ_DIR)/main.o \
			$(OBJ_DIR)/mod_atol.o \


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(MAKE) -C clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
