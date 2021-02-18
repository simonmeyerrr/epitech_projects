##
## EPITECH PROJECT, 2017
## minicut
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/utils/utils_string.c	\
		CFiles/utils/utils_int.c	\
		CFiles/utils/utils_memory.c	\
		CFiles/utils/utils_display.c	\
		CFiles/utils/get_next_line.c	\
		CFiles/utils/str_to_tab.c	\
		CFiles/parse_argument.c		\
		CFiles/manage_flag.c		\
		CFiles/action_flag.c		\
		CFiles/add_nb_list.c		\
		CFiles/display_minicut.c	\
		CFiles/choose_display.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/ -Wall -Wextra

LDFLAGS	=

CC	=	gcc -g

RM	=	rm -f

NAME	=	minicut

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
