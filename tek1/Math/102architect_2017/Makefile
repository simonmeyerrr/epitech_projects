##
## EPITECH PROJECT, 2017
## 102architect
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/error_management.c	\
		CFiles/operations.c

NAME	=	102architect

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -g -lm

clean:
	rm -f *~ vgcore*
	rm -f CFiles/*~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
