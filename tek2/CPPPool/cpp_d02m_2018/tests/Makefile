##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile unit tests
##

SRC			=	../ex00/add_mul.c	\
				../ex01/mem_ptr.c

SRC_UT		=	utils.c					\
				tests_add_mul_4param.c	\
				tests_add_mul_2param.c	\
				tests_my_strlen.c		\
				tests_add_str.c			\
				tests_add_str_struct.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

RM_FILE	=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror --coverage -I.

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
