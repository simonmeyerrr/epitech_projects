##
## EPITECH PROJECT, 2018
## project
## File description:
## Makefile
##

NAME	=	unit_tests

## Sources
SRC_PATH	=	../ex01

SRC			=	$(SRC_PATH)/AtmosphereRegulator.cpp	\
				$(SRC_PATH)/Engine.cpp				\
				$(SRC_PATH)/Errors.cpp				\
				$(SRC_PATH)/Oxygenator.cpp			\
				$(SRC_PATH)/WaterReclaimer.cpp

SRC_UT		=	tests_errors.cpp

OBJ			=	$(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)

## Remove
RM_FILE	=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
RM		=	rm -f

## Compilation
CC		=	g++
CFLAGS	+=	-W -Wall -Wextra -Werror --coverage -I$(SRC_PATH)
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
