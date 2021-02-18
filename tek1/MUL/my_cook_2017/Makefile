##
## EPITECH PROJECT, 2017
## my_cook
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/string.c	\
		CFiles/get_string_from_value.c	\
		CFiles/vector.c	\
		CFiles/init_game.c		\
		CFiles/init_texture_sprite.c	\
		CFiles/init_text.c		\
		CFiles/free_game.c	\
		CFiles/start_animation.c	\
		CFiles/main_menu.c		\
		CFiles/game.c			\
		CFiles/update_game.c		\
		CFiles/setting.c		\
		CFiles/end_game.c		\
		CFiles/pause.c

NAME	=	my_cook

CC	=	gcc

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(FILE) -I./include/ -lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio

debug:
	$(CC) -o $(NAME) $(FILE) -I./include/ -lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio -g

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
