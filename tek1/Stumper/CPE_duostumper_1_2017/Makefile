##
## EPITECH PROJECT, 2017
## head
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/util_string.c	\
		CFiles/get_next_line.c	\
		CFiles/parse_argument.c	\
		CFiles/detect_special_arg.c	\
		CFiles/display_file.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/

LDFLAGS	=

CC	=	gcc

RM	=	rm -f

NAME	=	head

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
