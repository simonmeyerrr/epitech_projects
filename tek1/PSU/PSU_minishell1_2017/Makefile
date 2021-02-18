##
## EPITECH PROJECT, 2017
## minishell1
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/str_function.c	\
		CFiles/free.c	\
		CFiles/get_next_line.c	\
		CFiles/my_str_to_word_array.c	\
		CFiles/my_env.c	\
		CFiles/my_cd.c	\
		CFiles/env_cmd.c	\
		CFiles/execution.c

NAME	=	mysh

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
