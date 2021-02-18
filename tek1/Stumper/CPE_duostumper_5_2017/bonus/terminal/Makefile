##
## EPITECH PROJECT, 2017
## hangman
## File description:
## Makefile
##

FILE	=	CFiles/main.c			\
		CFiles/utils/utils_string.c	\
		CFiles/utils/utils_int.c	\
		CFiles/utils/utils_memory.c	\
		CFiles/utils/utils_display.c	\
		CFiles/utils/get_next_line.c	\
		CFiles/utils/str_to_tab.c	\
		CFiles/init_hangman.c		\
		CFiles/display_game.c		\
		CFiles/display_hangman.c	\

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/ -Wall -Wextra -Werror

CC	=	gcc

RM	=	rm -f

NAME	=	hangman

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
