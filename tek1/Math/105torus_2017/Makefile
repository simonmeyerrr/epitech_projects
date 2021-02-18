##
## EPITECH PROJECT, 2017
## 105torus_2017
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/bisection.c	\
		CFiles/newton.c	\
		CFiles/secant.c

NAME	=	105torus

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -lm

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
