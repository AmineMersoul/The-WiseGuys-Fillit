NAME = tetriminos

SOURCE = main.c 
OUT = tetriminos.out
LIBS = libft/libft.a get_next_line/get_next_line.c tetriminos/tetriminos.a
FLAGS = -Wall -Wextra -Werror

run:
	gcc $(FLAGS) $(SOURCE) $(LIBS) -o $(OUT)

all: $(NAME)

mlibft:
	cd libft && $(MAKE) re && $(MAKE) clean

mtetriminos:
	cd tetriminos && $(MAKE) re && $(MAKE) clean

$(NAME): mlibft mtetriminos run

clean:
	cd libft && $(MAKE) clean
	cd tetriminos && $(MAKE) clean

fclean: clean
	cd libft && $(MAKE) fclean
	cd tetriminos && $(MAKE) fclean
	rm -rf $(OUT)

re: fclean all