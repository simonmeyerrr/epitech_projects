##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for unit tests
##

SRC_DIR	=	..

SRC	=	$(SRC_DIR)/sort_numbers.c

SRC_UT_DIR	=	.

SRC_UT	=	$(SRC_UT_DIR)/tests_swap_elem.c	\
		$(SRC_UT_DIR)/test_bubble.c

OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS	=	-Wall -Wextra --coverage

LDFLAGS	=	-lcriterion -lgcov

NAME	=	units

all:	$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcda *.gcno
	rm -f ../*.gcda ../*.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all
