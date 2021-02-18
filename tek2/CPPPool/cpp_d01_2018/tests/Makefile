##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile unit tests
##

SRC			=	../ex00/white_rabbit.c	\
				../ex01/menger.c

SRC_UT		=	utils.c							\
				tests_follow_the_white_rabbit.c	\
				tests_my_pow.c					\
				tests_my_get_nbr.c				\
				tests_is_nb_valid.c				\
				tests_menger.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

RM_FILE	=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror --coverage

LDFLAGS	=	-lcriterion -lgcov

NAME	=	unit_tests

RED		=	\033[31;1m

GREEN	=	\033[32;1m

NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re
