##
## EPITECH PROJECT, 2017
## my_runner
## File description:
## Makefile
##

FILE	=	CFiles/main.c			\
		CFiles/string_vector_rect.c	\
		CFiles/game/game.c		\
		CFiles/game/display_game.c	\
		CFiles/game/event_game.c	\
		CFiles/prepare_game/open_map.c			\
		CFiles/prepare_game/prepare_game.c		\
		CFiles/prepare_game/prepare_texture_sprite.c	\
		CFiles/prepare_game/prepare_obj.c		\
		CFiles/prepare_game/free_struct_game.c		\
		CFiles/update/update_game.c	\
		CFiles/update/jump.c		\
		CFiles/update/detect_colision.c	\
		CFiles/menu/menu.c		\
		CFiles/menu/play_menu.c		\
		CFiles/menu/settings.c		\
		CFiles/menu/prepare_menu.c	\
		CFiles/menu/free_struct_menu.c

NAME	=	my_runner

CC	=	gcc

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(FILE) -I./include/ -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

debug:
	$(CC) -o $(NAME) $(FILE) -I./include/ -g -lc_graph_prog

clean:
	rm -f *~ vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
