##
## EPITECH PROJECT, 2017
## hidenp
## File description:
## Makefile
##

FILE	=	main.c

NAME	=	hidenp

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/

clean:
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
