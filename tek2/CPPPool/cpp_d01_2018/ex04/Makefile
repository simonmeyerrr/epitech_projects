##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile ex04
##

SRC		=	main.c			\
			menger.c		\
			bitmap_header.c	\
			drawing.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -std=gnu11

NAME	=	menger_face

RED		=	\033[31;1m

GREEN	=	\033[32;1m

BLUE	=	\033[34;1m

NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.c
	@echo -e "$(BLUE)[CC] $@ -> $<$(NORMAL)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean: clean
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run:
	@make -C ../tests/ re && ../tests/unit_tests

.PHONY: all clean fclean re tests_run
