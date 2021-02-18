##
## EPITECH PROJECT, 2017
## my_hunter
## File description:
## Makefile
##

FILE	=	CFiles/main.c		\
		CFiles/fonc_str.c	\
		CFiles/vector_rect.c	\
		CFiles/init.c		\
		CFiles/init2.c		\
		CFiles/init3.c		\
		CFiles/start_menu.c	\
		CFiles/game.c		\
		CFiles/hit_box.c	\
		CFiles/nb_to_str.c	\
		CFiles/bird.c		\
		CFiles/end_menu.c	\
		CFiles/prepare.c	\
		CFiles/destroy.c

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILE) -lc_graph_prog -g -I./include/

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
