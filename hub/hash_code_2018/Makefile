##
## EPITECH PROJECT, 2017
## google_hash_code
## File description:
## Makefile
##

FILE	=	$(wildcard CFiles/*.c)

NAME	=	google_hash_code

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
