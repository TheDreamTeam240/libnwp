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

TEST_SRC_DIR = ./tests/src
TEST_OBJ_DIR = ./tests/obj
TEST_BIN_DIR = $(BIN_DIR)

TEST_SRC = $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJ = $(TEST_SRC:$(TEST_SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.o)
TEST_COVERAGE = $(TEST_SRC:$(TEST_SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.gcno) \
	$(TEST_SRC:$(TEST_SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.gcda)
TEST_BIN = $(TEST_BIN_DIR)/unit_tests

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

tests_run: $(TEST_BIN)
	LD_LIBRARY_PATH=. $(TEST_BIN) --verbose

$(TEST_BIN): CFLAGS += --coverage
$(TEST_BIN): $(TEST_OBJ) $(NAME)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) -lcriterion -L$(BIN_DIR) -l$(NAME)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re tests_run
