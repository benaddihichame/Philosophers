
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -pthread -g3
NAME = philosopher
SRC_DIR = src
OBJ_DIR = obj
CMD_DIR = cmd

SRCS = $(SRC_DIR)/init.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/time.c \
			$(SRC_DIR)/mod_atol.c \
			$(SRC_DIR)/main.c \


OBJS = $(OBJ_DIR)/init.o \
			$(OBJ_DIR)/utils.o \
			$(OBJ_DIR)/time.o \
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
