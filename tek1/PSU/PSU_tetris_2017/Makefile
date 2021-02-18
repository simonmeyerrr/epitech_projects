##
## EPITECH PROJECT, 2017
## tetris
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/string.c	\
		CFiles/memory.c	\
		CFiles/parse_argument.c	\
		CFiles/disp_debug.c	\
		CFiles/get_tetrimino.c	\
		CFiles/play_game.c	\
		CFiles/sort.c

OBJ	=	$(FILE:.c=.o)

NAME	=	tetris

CC	=	gcc

RM	=	rm -f

CFLAGS  =       -I./include/ -lncurses

DFLAGS	=	-g -Wall -Wextra -ggdb

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(DFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~ vgcore*

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
