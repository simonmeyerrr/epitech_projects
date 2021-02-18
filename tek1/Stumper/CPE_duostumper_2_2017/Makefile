##
## EPITECH PROJECT, 2017
## my_ginger
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/init_ginger.c	\
		CFiles/display_ginger.c	\
		CFiles/move_ginger.c	\
		CFiles/str_to_tab.c	\
		CFiles/parse_argument.c	\
		CFiles/move_on_map.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/

LDFLAGS	=

CC	=	gcc

RM	=	rm -f

NAME	=	my_ginger

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
