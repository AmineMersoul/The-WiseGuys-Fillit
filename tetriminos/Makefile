NAME = tetriminos

SOURCE = *.c 
OFILES = *.o
INCLUDES = tetriminos.h
LIB = tetriminos.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SOURCE) $(INCLUDES)
	ar rc $(LIB) $(OFILES)
	ranlib $(LIB)

clean:
	rm -f $(OFILES)
	rm -f tetriminos.h.gch

fclean: clean
	rm -f $(LIB)

re: fclean all