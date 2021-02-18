##
## EPITECH PROJECT, 2017
## dante_solver
## File description:
## Makefile
##

FILE	=	CFiles/wordtab.c		\
		CFiles/create_maze.c		\
		CFiles/generate_maze.c		\
		CFiles/get_possibility.c	\
		CFiles/memory.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/

LDFLAGS	=

CC	=	gcc

RM	=	rm -f

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
