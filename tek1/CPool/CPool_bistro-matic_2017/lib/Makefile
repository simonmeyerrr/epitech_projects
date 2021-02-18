##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile lib bistro-matic
##

FILE	=	my_putchar.c	\
		my_strlen.c	\
		my_putstr.c	\
		my_getnbr.c	\
		priolevel.c	\
		my_charisope.c	\
		nblen.c		\
		my_rev_rpn.c	\
		my_strcmp.c	\
		zero.c		\
		my_rpn_size.c	\
		my_revstr.c	\
		epur_str.c

OBJ	=	$(FILE:.c=.o)

NAME	=	libmy.a

all:	compil

compil:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) *~

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
