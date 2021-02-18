##
## EPITECH PROJECT, 2018
## cpp_d06_2018
## File description:
## Makefile ex01
##

SRC		=	MyConvertTemp.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	my_convert_temp

RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.cpp
	@echo -e "$(BLUE)[CC] $< -> $@$(NORMAL)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean: clean
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re
