##
## EPITECH PROJECT, 2017
## my_exec
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/my_str_to_word_array.c

NAME	=	my_exec

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/

debug:
	gcc -o $(NAME) $(FILE) -I./include/ -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
