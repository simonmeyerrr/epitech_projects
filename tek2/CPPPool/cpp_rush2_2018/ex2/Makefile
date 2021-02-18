##
## EPITECH PROJECT, 2022
## cpp_rush2_2018
## File description:
## Makefile
##

SRC	=	Main.cpp								\
		Santa.cpp								\
		../ex1/Object/Object.cpp				\
		../ex1/Object/Toy/Toy.cpp						\
		../ex1/Object/Toy/Teddy.cpp					\
		../ex1/Object/Toy/LittlePony.cpp				\
		../ex1/Object/Wrap/Wrap.cpp					\
		../ex1/Object/Wrap/Box.cpp						\
		../ex1/Object/Wrap/Paper.cpp					\
		XMLDeserializer/XMLDeserializer.cpp



OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -f

CC	=	g++

CFLAGS	+=	-W -Wall -Wextra -Werror -g

NAME	=	santa

RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.cpp
	@echo -e "$(BLUE)[CC] $@ -> $<$(NORMAL)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re
