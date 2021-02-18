##
## EPITECH PROJECT, 2017
## info_file
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/disp_fonc.c	\
		CFiles/info_file.c

NAME	=	info_file

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
