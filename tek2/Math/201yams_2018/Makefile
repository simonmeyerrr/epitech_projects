##
## EPITECH PROJECT, 2018
## 201yams_2018
## File description:
## Makefile
##

NAME	=	201yams

## Sources
SRC		=	src/main.cpp	\
			src/Yams.cpp

OBJ		=	$(SRC:.cpp=.o)

## Compile
CC		=	g++
CFLAGS	=	-W -Wall -Wextra -Werror -I./include

## Remove
RM		=	rm -f

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
	$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run:
	@make -C tests/ tests_run

.PHONY: all clean fclean re tests_run
