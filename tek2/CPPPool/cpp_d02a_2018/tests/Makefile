##
## EPITECH PROJECT, 2018
## cpp_d02a_2018
## File description:
## Makefile unit tests
##

SRC	=	../ex00/info.c	\
		../ex00/list_add.c	\
		../ex00/list_del.c	\
		../ex00/list_get.c

SRC_UT	=	utils.c	\
			tests_list_get_size.c	\
			tests_list_is_empty.c	\
			tests_list_dump.c	\
			tests_list_add_elem_at_front.c	\
			tests_list_add_elem_at_back.c	\
			tests_list_add_elem_at_position.c	\
			tests_list_del_elem_at_front.c	\
			tests_list_del_elem_at_back.c	\
			tests_list_del_elem_at_position.c	\
			tests_list_get_elem_at_front.c	\
			tests_list_get_elem_at_back.c	\
			tests_list_get_elem_at_position.c	\
			tests_list_get_first_node_with_value.c

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
