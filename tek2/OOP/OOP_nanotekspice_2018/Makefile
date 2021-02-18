##
## EPITECH PROJECT, 2022
## OOP_nanotekspice_2018
## File description:
## Makefile
##

NAME	=	nanotekspice

## Sources
SRC		=	src/main.cpp	\
			src/Errors.cpp	\
			src/Parser.cpp	\
			src/Nanotekspice.cpp	\
			src/Components/Factory.cpp	\
			src/Components/Link.cpp		\
			src/Components/Gates.cpp	\
			src/Components/Input.cpp	\
			src/Components/True.cpp		\
			src/Components/False.cpp	\
			src/Components/Clock.cpp    \
			src/Components/Output.cpp	\
			src/Components/C4011.cpp    \
			src/Components/C4069.cpp    \
			src/Components/C4081.cpp    \
			src/Components/C4503.cpp    \
			src/Components/C4030.cpp    \
			src/Components/C4012.cpp    \
			src/Components/C4023.cpp    \
			src/Components/C4071.cpp    \
			src/Components/C4001.cpp    \
			src/Components/C4514.cpp    \
			src/Components/C4515.cpp    \

OBJ		=	$(SRC:.cpp=.o)

## Compile
CC		=	g++
CFLAGS	=	-W -Wall -Wextra -Werror

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
	@make -C tests/ clean
	$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@make -C tests/ fclean
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run:
	@make -C tests/ tests_run

.PHONY: all clean fclean re tests_run
