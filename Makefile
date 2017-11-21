SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)
NAME = fillit
FLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT_DIR = libft/
INC_DIR = includes/

all: $(NAME) $(SRC)

$(NAME): create_lib $(OBJ)
	@$(CC) $(FLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft
	@echo "Create fillit"

create_lib:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $^ -I$(INC_DIR)

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "Delete object-files"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "Delete fillit"

re: fclean all
