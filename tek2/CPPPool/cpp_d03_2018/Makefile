##
## EPITECH PROJECT, 2018
## cpp_d03_2018
## File description:
## Makefile
##

SRC		=	utils.c			\
			constructor.c	\
			assign.c		\
			append.c		\
			at.c			\
			clear.c			\
			size.c			\
			compare.c		\
			copy.c			\
			c_str.c			\
			empty.c			\
			find.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -I.

RM		=	rm -f

NAME	=	libstring.a

RED		=	\033[31;1m

GREEN	=	\033[32;1m

NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) && echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean: clean
	@make -C ./tests/ fclean
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run:
	@make -C ./tests/ re && ./tests/unit_tests && make -C ./tests/ clean

.PHONY: all clean fclean re
