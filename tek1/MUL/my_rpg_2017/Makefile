##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## Makefile
##

FILE	=	src/main.c	\
		src/utils/manage_arg.c		\
		src/utils/utils_string.c	\
		src/utils/memory.c		\
		src/utils/get_string_nb.c	\
		src/utils/str_to_tab.c		\
		src/utils/get_next_line.c	\
		src/utils/vector_tab.c		\
		src/utils/json_parser.c		\
		src/utils/json_creator.c	\
		src/utils/utils_setting.c	\
		src/utils/utils_move_player.c	\
		src/utils/fight_attack.c	\
		src/utils/particles.c		\
		src/utils/snow.c		\
		src/initialisation/init_global.c		\
		src/initialisation/init_asset.c			\
		src/initialisation/init_texture_sprite.c	\
		src/initialisation/init_game.c			\
		src/free_struct/free_global.c	\
		src/free_struct/free_asset.c	\
		src/free_struct/free_game.c	\
		src/interaction/utils_inter.c		\
		src/interaction/inter_logan_paul.c	\
		src/interaction/inter_knuckles.c	\
		src/interaction/inter_object.c		\
		src/interaction/inter_npc.c		\
		src/interaction/inter_jahar.c		\
		src/interaction/inter_lama.c		\
		src/csfml/global_draw.c		\
		src/csfml/global_event.c	\
		src/csfml/global_update.c	\
		src/csfml/network.c		\
		src/csfml/sign_up.c		\
		src/csfml/log_in.c		\
		src/csfml/update_user.c		\
		src/csfml/get_user_info.c	\
		src/scene/s0_main_menu/event.c		\
		src/scene/s0_main_menu/update.c		\
		src/scene/s0_main_menu/display.c	\
		src/scene/s1_log_in/event.c		\
		src/scene/s1_log_in/update.c		\
		src/scene/s1_log_in/display.c		\
		src/scene/s2_sign_up/event.c		\
		src/scene/s2_sign_up/update.c		\
		src/scene/s2_sign_up/display.c		\
		src/scene/s3_connected/event.c		\
		src/scene/s3_connected/update.c		\
		src/scene/s3_connected/display.c	\
		src/scene/s4_settings/event.c		\
		src/scene/s4_settings/update.c		\
		src/scene/s4_settings/display.c		\
		src/scene/s5_animation/event.c		\
		src/scene/s5_animation/update.c		\
		src/scene/s5_animation/display.c	\
		src/scene/s6_game/event.c		\
		src/scene/s6_game/update.c		\
		src/scene/s6_game/display.c		\
		src/scene/s7_inventory/event.c		\
		src/scene/s7_inventory/update.c		\
		src/scene/s7_inventory/display.c	\
		src/scene/s8_fight/event.c		\
		src/scene/s8_fight/update.c		\
		src/scene/s8_fight/display.c		\
		src/scene/s9_game_menu/event.c		\
		src/scene/s9_game_menu/update.c		\
		src/scene/s9_game_menu/display.c	\
		src/scene/s10_help/event.c		\
		src/scene/s10_help/update.c		\
		src/scene/s10_help/display.c

OBJ	=	$(FILE:.c=.o)

NAME	=	my_rpg

CC	=	gcc

RM	=	rm -f

CFLAGS  =       -I./include/

LDFLAGS	=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio\
		-lcsfml-network -lm

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	@echo -e ""
	@echo -e "\t\033[32;1m+---------------+"
	@echo -e "\t|\033[34;1mCompilation OK!\033[32;1m|"
	@echo -e "\t+---------------+\n\033[0m"

%.o:	%.c
	@echo -e "\033[34;1m[COMPILING] \033[32;1m$<\033[31;1m ->"\
	" \033[33;1m$@\033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) && \
	echo -e "\033[31;1m[REMOVING] \033[33;1mEvery .o files\033[0m"

fclean:	clean
	@$(RM) $(NAME) && \
	echo -e "\033[31;1m[REMOVING] \033[33;1m$(NAME)\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
