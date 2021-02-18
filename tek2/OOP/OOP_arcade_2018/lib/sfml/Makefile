##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile
##

NAME	=	lib_arcade_sfml.so

## Sources
SRC		=	Sfml.cpp				\
			../../utils/Event.cpp	\
			../../utils/Vector.cpp

OBJ		=	$(SRC:.cpp=.o)

## Compile
CC		=	g++ -fPIC
CFLAGS	=	-W -Wall -Wextra -Werror -I../../utils/ -I./
LDFLAGS	=	-shared -lsfml-graphics -lsfml-window -lsfml-system

## Remove
RM		=	rm -f

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@printf "$(BLUE)[CC] $(NAME)$(NORMAL)\n"
	@$(CC) $(LDFLAGS) -o ../$(NAME) $(OBJ)
	@printf "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)\n"

%.o: %.cpp
	@printf "$(BLUE)[CC] $< -> $@$(NORMAL)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) $(RM_FILE)
	@printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"

fclean:
	@$(RM) $(OBJ) $(RM_FILE)
	@printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"
	@$(RM) ../$(NAME)
	@printf "$(RED)[RM] $(NAME)$(NORMAL)\n"

re: fclean all

.PHONY: all clean fclean re tests_run
