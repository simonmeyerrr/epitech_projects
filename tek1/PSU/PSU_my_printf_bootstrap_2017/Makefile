##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile my_printf lib
##

FILE	=	bootstrap.c	\
		fonc.c

OBJ	=	$(FILE:.c=.o)

NAME	=	libmy.a

all:	compil

compil:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re compil
