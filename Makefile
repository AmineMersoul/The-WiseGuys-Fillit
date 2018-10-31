NAME = fillit

SOURCE = main.c 
LIBS = libft/libft.a get_next_line/get_next_line.c tetriminos/tetriminos.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	cd tetriminos && $(MAKE)
	gcc $(FLAGS) $(SOURCE) $(LIBS) -o $(NAME)

clean:
	cd libft && $(MAKE) clean
	cd tetriminos && $(MAKE) clean

fclean: clean
	cd libft && $(MAKE) fclean
	cd tetriminos && $(MAKE) fclean
	rm -rf $(NAME)

re: fclean all