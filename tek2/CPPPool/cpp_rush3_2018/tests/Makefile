##
## EPITECH PROJECT, 2018
## project
## File description:
## Makefile
##

NAME	=	unit_tests

## Sources
SRC_PATH	=	../src

SRC			=	$(SRC_PATH)/Parser/Parser.cpp 				\


SRC_UT		=	test_Parser.cpp								\


OBJ			=	$(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)

## Remove
RM		=	rm -f
RM_FILE	=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

## Compilation
CC		=	g++
CFLAGS	+=	-W -Wall -Wextra --coverage
LDFLAGS	=	-lcriterion -lgcov

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run:	re	clean
	@./unit_tests

.PHONY: all clean fclean re tests_run
