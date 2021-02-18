##
## EPITECH PROJECT, 2017
## my_pushswap
## File description:
## Makefile
##

FILE	=	CFiles/main.c		\
		CFiles/push_swap.c	\
		CFiles/swap.c		\
		CFiles/move.c		\
		CFiles/rotate.c		\
		CFiles/rev_rotate.c	\
		CFiles/display_fonc.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	+=	-O2

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I./include/ -g

clean:
	rm -f *~ vgcore*
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
