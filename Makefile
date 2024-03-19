##
## EPITECH PROJECT, 2024
## libnwp
## File description:
## Makefile
##

NAME = nwp

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -fPIC
LDFLAGS =

SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = .

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
COVERAGE = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.gcno) \
	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.gcda)
BIN = $(BIN_DIR)/lib$(NAME).so

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $(BIN) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	rm -f $(BIN)
	rm -f $(COVERAGE)
	rm -f $(TEST_COVERAGE)
	rm -f $(TEST_BIN)

re: fclean all

.PHONY: all clean fclean re
