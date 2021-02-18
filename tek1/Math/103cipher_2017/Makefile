##
## EPITECH PROJECT, 2017
## 103cipher
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/encrypt.c	\
		CFiles/decrypt.c	\
		CFiles/matrice.c	\
		CFiles/reverse_matrice.c

NAME	=	103cipher

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
