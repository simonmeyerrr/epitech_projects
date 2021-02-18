##
## EPITECH PROJECT, 2022
## CPP_plazza_2018
## File description:
## Makefile
##

NAME	=	plazza

## Sources
SRC		=	src/Main.cpp	                \
			src/classes/Reception.cpp		\
			src/classes/Kitchen.cpp	        \
			src/classes/Cook.cpp	        \
			src/classes/Stock.cpp	        \
			src/classes/Pizza.cpp	        \
			src/classes/Serialization.cpp   \
			src/classes/Args.cpp            \
			src/classes/MsgQClient.cpp      \
			src/classes/MsgQServer.cpp      \
			src/classes/Mutex.cpp

OBJ		=	$(SRC:.cpp=.o)

## Compile
CC		=	g++ -g
CFLAGS	=	-W -Wall -Wextra -Werror
LDFLAGS	=	-lpthread

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
	printf "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)\n"

%.o: %.cpp
	@printf "$(BLUE)[CC] $< -> $@$(NORMAL)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@##make -C tests/ clean
	$(RM) $(OBJ) $(RM_FILE) && \
	printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"

fclean:
	@##make -C tests/ fclean
	@$(RM) $(OBJ) $(RM_FILE) && \
	printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"
	@$(RM) $(NAME) && printf "$(RED)[RM] $(NAME)$(NORMAL)\n"

re: fclean all

tests_run:
	@make -C tests/ tests_run

.PHONY: all clean fclean re tests_run
