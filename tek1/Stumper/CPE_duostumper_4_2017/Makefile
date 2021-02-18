##
## EPITECH PROJECT, 2017
## mixword
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
		CFiles/utils/my_get_opt.c	\
		CFiles/utils/my_get_opt2.c	\
		CFiles/init_mixword.c		\
		CFiles/parse_argument.c		\
		CFiles/algo_to_mixword.c	\
		CFiles/display_mixword.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/ -Wall -Wextra

LDFLAGS	=

CC	=	gcc

RM	=	rm -f

NAME	=	mixword

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
