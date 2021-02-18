##
## EPITECH PROJECT, 2018
## project
## File description:
## Makefile
##

NAME		=	unit_tests

## Sources
SRC			=	../src/Errors.cpp	\
				../src/Components/Link.cpp	\
				../src/Components/Factory.cpp	\
				../src/Components/Gates.cpp     \
				../src/Components/Input.cpp		\
				../src/Components/True.cpp		\
				../src/Components/False.cpp		\
				../src/Components/Output.cpp	\
				../src/Components/Clock.cpp     \
				../src/Components/C4011.cpp     \
				../src/Components/C4081.cpp     \
				../src/Components/C4503.cpp     \
				../src/Components/C4069.cpp     \
				../src/Components/C4030.cpp     \
				../src/Components/C4012.cpp     \
				../src/Components/C4023.cpp     \
				../src/Components/C4071.cpp     \
				../src/Components/C4001.cpp     \
				../src/Components/C4514.cpp     \
				../src/Components/C4515.cpp     \

SRC_UT		=	redirect_all_std.cpp	\
				tests_input.cpp		\
				tests_true.cpp		\
				tests_false.cpp		\
				tests_clock.cpp     \
				tests_output.cpp	\
				tests_c4011.cpp     \
				tests_c4081.cpp     \
				tests_c4503.cpp     \
				tests_c4069.cpp     \
				tests_c4030.cpp     \
				tests_c4012.cpp     \
				tests_c4023.cpp     \
				tests_c4071.cpp     \
				tests_c4001.cpp     \
				tests_c4514.cpp     \
				tests_c4515.cpp     \
				tests_other.cpp     \

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
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.cpp
	@echo -e "$(BLUE)[CC] $< -> $@$(NORMAL)"
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
