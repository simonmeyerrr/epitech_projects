##
## EPITECH PROJECT, 2018
## OOP_arcade_2018
## File description:
## Makefile
##

NAME		=	unit_tests

## Sources
SRC			=

SRC_UT		=	redirect_all_std.cpp

OBJ			=	$(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)

## Remove
RM			=	rm -f
RM_FILE		=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

## Compilation
CC			=	g++
CFLAGS		+=	-W -Wall -Wextra -Werror --coverage
LDFLAGS		=	-lcriterion -lgcov

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@printf "$(BLUE)[CC] $(NAME)$(NORMAL)\n"
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)\n"

%.o: %.cpp
	@printf "$(BLUE)[CC] $< -> $@$(NORMAL)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"

fclean:
	@$(RM) $(OBJ) $(RM_FILE)
	@printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"
	@$(RM) $(NAME)
	@printf "$(RED)[RM] $(NAME)$(NORMAL)\n"

re: fclean all

tests_run:	re	clean
	@./unit_tests

.PHONY: all clean fclean re tests_run