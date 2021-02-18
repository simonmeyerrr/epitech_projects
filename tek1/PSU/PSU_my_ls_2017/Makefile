##
## EPITECH PROJECT, 2017
## ah
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/display.c	\
		CFiles/disp_d.c		\
		CFiles/flag_list.c		\
		CFiles/disp_normal.c

NAME	=	my_ls

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -I./include/ -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
