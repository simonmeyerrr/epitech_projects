##
## EPITECH PROJECT, 2017
## ah
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/object.c

NAME	=	104intersection

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -lm

debug:
	gcc -o $(NAME) $(FILE) -I./include/ -lm -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
