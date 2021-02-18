##
## EPITECH PROJECT, 2017
## matchstick
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/get_next_line.c	\
		CFiles/string.c	\
		CFiles/player.c	\
		CFiles/robot.c	\
		CFiles/algo.c

NAME	=	matchstick

CC	=	gcc

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(FILE) -I./include/

debug:
	$(CC) -o $(NAME) $(FILE) -I./include/ -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
