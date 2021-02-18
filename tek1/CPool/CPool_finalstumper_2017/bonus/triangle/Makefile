##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Rush3
##


SRC	=	triangle.c	\
		display.c

NAME	=	triangle

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -Iinclude

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
