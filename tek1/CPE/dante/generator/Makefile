##
## EPITECH PROJECT, 2017
## dante_generator
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/string.c	\
		CFiles/memory.c	\
		CFiles/create_maze.c		\
		CFiles/generate_maze.c		\
		CFiles/get_possibility.c	\
		CFiles/make_maze_imperfect.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/

LDFLAGS	=

CC	=	gcc -O2

RM	=	rm -f

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
