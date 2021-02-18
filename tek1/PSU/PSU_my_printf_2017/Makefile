##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile my_printf lib
##

FILE	=	my_printf/my_printf.c		\
		my_printf/printf_character.c	\
		my_printf/printf_int.c		\
		my_printf/printf_pourcent.c	\
		my_printf/printf_string.c	\
		my_printf/printf_octal.c	\
		my_printf/printf_hexadecimal.c	\
		my_printf/printf_binary.c	\
		my_printf/printf_pointer.c	\
		my_printf/printf_unsigned_int.c	\
		my_printf/printf_string_octal.c

OBJ	=	$(FILE:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re compil
