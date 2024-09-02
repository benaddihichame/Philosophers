
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude -pthread -g3
NAME = philosopher
SRC_DIR = src
OBJ_DIR = obj
CMD_DIR = cmd

SRCS = $(SRC_DIR)/the_table.c \
			$(SRC_DIR)/utils.c \


OBJS = $(OBJ_DIR)/the_table.o \
			$(OBJ_DIR)/utils.o \

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
