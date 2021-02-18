##
## EPITECH PROJECT, 2022
## cpp_rush2_2018
## File description:
## Makefile
##

SRC	=	Main.cpp							\
		Object/Object.cpp					\
		Object/Toy/Toy.cpp					\
		Object/Toy/Teddy.cpp				\
		Object/Toy/LittlePony.cpp			\
		Object/Wrap/Wrap.cpp				\
		Object/Wrap/Box.cpp					\
		Object/Wrap/Paper.cpp				\
		Table/ITable.cpp					\
		Table/Table.cpp						\
		Table/TableRand.cpp					\
		ConveyorBelt/IConveyorBelt.cpp		\
		ConveyorBelt/ConveyorBeltRand.cpp	\
		ConveyorBelt/ConveyorBelt.cpp		\
		Elf/IElf.cpp						\
		Elf/Elf.cpp                         \
		XMLSerializer/XMLSerializer.cpp		\
		Algo/Algo.cpp

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -f

CC	=	g++ -g

CFLAGS	+=	-Wall -Wextra -Werror

NAME	=	elves

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
