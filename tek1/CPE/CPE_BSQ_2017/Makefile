##
## EPITECH PROJECT, 2017
## bsq
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/load_map_var.c	\
		CFiles/search_square.c

NAME	=	bsq

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
