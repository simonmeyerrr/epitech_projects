##
## EPITECH PROJECT, 2018
## cpp_d01_2018
## File description:
## Makefile unit tests
##

SRC_PATH	=	../ex00

SRC			=	$(SRC_PATH)/Picture.cpp	\
				$(SRC_PATH)/Toy.cpp

SRC_UT		=	tests_toy.cpp	\
				tests_picture.cpp

OBJ		=	$(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)
RM_FILE	=	$(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

RM		=	rm -f
CC		=	g++

CFLAGS	+=	-W -Wall -Wextra -Werror --coverage -I$(SRC_PATH)
LDFLAGS	=	-lcriterion -lgcov

NAME	=	unit_tests

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
