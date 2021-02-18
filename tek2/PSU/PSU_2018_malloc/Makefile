##
## EPITECH PROJECT, 2022
## PSU_2018_malloc
## File description:
## Makefile
##

NAME	=	libmy_malloc.so

## Sources
SRC	=	src/malloc.c	\
		src/realloc.c	\
		src/free.c		\
		src/thread.c	\
		src/show_alloc_mem.c

OBJ	=	$(SRC:.c=.o)

## Compile
CC		=	gcc -g
CFLAGS	=	-W -Wall -Wextra -I./include -fPIC

## Remove
RM	=	rm -f

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -shared -o $(NAME) $(OBJ) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.c
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

.PHONY: all clean fclean re
