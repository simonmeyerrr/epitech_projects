##
## EPITECH PROJECT, 2018
## unit tests
## File description:
## Makefile
##

SRC_DIR		=

SRC			=

SRC_UT_DIR	=	.

SRC_UT		=

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
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re