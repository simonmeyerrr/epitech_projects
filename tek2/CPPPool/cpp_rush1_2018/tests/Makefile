##
## EPITECH PROJECT, 2018
## cpp_rush1_2018
## File description:
## Makefile unit tests
##

SRC		=	provided_files/player.c	\
			../new.c				\
			../point.c				\
			../vertex.c				\
			../int.c				\
			../char.c

SRC_UT	=	tests_redirect_output.c	\
			tests_new_delete.c		\
			tests_point.c			\
			tests_vertex.c			\
			tests_int.c				\
			tests_char.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

RM_FILE	=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror --coverage -I. -I.. -I./provided_files

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
	echo -e "$(RED)[RM] $(NAME)'s object files and coverage files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re