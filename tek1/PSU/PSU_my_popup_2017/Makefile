##
## EPITECH PROJECT, 2017
## ah
## File description:
## Makefile
##

FILE	=	CFiles/main.c

NAME	=	my_popup

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -g -lncurses

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
