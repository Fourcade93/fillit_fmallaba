SRC = clean_matrix.c fill_matrix.c init_matrix.c main.c print_square.c \
put_tetro.c read_file.c helpers.c
OBJ = $(SRC:.c=.o)
NAME = fillit
FLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "Create fillit"

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@echo "Delete object-files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Delete fillit"

re: fclean all
