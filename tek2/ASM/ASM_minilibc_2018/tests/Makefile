##
## EPITECH PROJECT, 2022
## ASM_minilibc_2018
## File description:
## Makefile
##

NAME		=	unit_tests

## Sources
SRC			=	tests_memcpy.c		\
				tests_memmove.c		\
				tests_memset.c		\
				tests_rindex.c		\
				tests_strcasecmp.c	\
				tests_strchr.c		\
				tests_strcmp.c		\
				tests_strcspn.c		\
				tests_strlen.c		\
				tests_strncmp.c		\
				tests_strpbrk.c		\
				tests_strstr.c

OBJ			=	$(SRC:.c=.o)

## Remove
RM			=	rm -f

## Compilation
CC			=	gcc
CFLAGS		+=	-W -Wall -Wextra -Werror
LDFLAGS		=	-lcriterion -ldl

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.c
	@echo -e "$(BLUE)[CC] $<\t-> $@$(NORMAL)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run: all
	@./unit_tests

.PHONY: all clean fclean re tests_run