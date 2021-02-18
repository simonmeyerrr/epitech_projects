##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

FILE	=	bistro/main.c		\
		bistro/base.c		\
		evalexpr/evalexpr.c	\
		evalexpr/my_rpn.c	\
		evalexpr/ope_to_rpn.c	\
		evalexpr/calcul.c	\
		addinf/addinf_main.c	\
		addinf/add_pos.c	\
		addinf/fcommu.c		\
		addinf/minus.c		\
		multinf/mult.c		\
		subinf/addinf_main.c

OBJ 	= 	$(SRC:.c=.o)

CFLAGS	= 	-Wall -Wextra -I./include/

LDFLAGS	= 	-L lib -lmy

RM	= 	rm -f

NAME	=	calc

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib
	$(CC) $(OBJ) -o $(NAME) $(FILE) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./lib clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib fclean

re:	fclean all

.PHONY:	all clean fclean re
