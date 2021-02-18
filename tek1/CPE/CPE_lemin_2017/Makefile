##
## EPITECH PROJECT, 2017
## lemin_2017
## File description:
## Makefile
##

FILE	=	CFiles/main.c	\
		CFiles/string.c	\
		CFiles/string2.c	\
		CFiles/memory.c	\
		CFiles/get_next_line.c	\
		CFiles/str_to_tab.c	\
		CFiles/init_global.c	\
		CFiles/get_input_info.c	\
		CFiles/init_room.c	\
		CFiles/init_tunnel.c	\
		CFiles/add_tunnel_to_room.c	\
		CFiles/search_path.c	\
		CFiles/display_result.c	\
		CFiles/display_result2.c	\
		CFiles/my_free_global.c

OBJ	=	$(FILE:.c=.o)

CFLAGS	=	-I./include/

LDFLAGS	=

CC	=	gcc -g

RM	=	rm -f

NAME	=	lem_in

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
