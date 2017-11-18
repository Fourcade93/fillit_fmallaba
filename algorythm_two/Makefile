SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)
NAME = fillit
FLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT_DIR = libft/
INC_DIR = includes/

all: $(NAME) $(SRC)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	@echo "Create fillit "

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $^ -I$(INC_DIR)

clean:
	@/bin/rm -f $(OBJ)
	@echo "Delete object-files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Delete fillit"

re: fclean all