SRC = main.c read_file.c change_comb.c fill_matrix.c
OBJ = $(SRC:.c=.o)
NAME = fillit
FLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT_DIR = libft/

all: $(NAME) $(SRC)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft
	@echo "Create fillit "

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $^ -I$(LIBFT_DIR)

clean:
	@/bin/rm -f $(OBJ)
	@echo "Delete object-files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Delete fillit"

re: fclean all