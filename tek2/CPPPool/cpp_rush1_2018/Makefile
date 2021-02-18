##
## EPITECH PROJECT, 2018
## cpp_rush1_2018
## File description:
## Makefile
##

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
NORMAL	=	\033[0m

## Basic rules
all:	ex01 ex02 ex03 ex04 ex05

tests_run:
	@make -C tests/ re && ./tests/unit_tests ; make -C tests/ clean

re: fclean all

## Compilation
CC		=	gcc -g
CFLAGS	+=	-W -Wall -Wextra -Werror -std=gnu11
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

## Exercice 01
SRC1	=	ex01.c player.c new.c
OBJ1	=	$(SRC1:.c=.o)
ex01:	$(OBJ1)
	@$(CC) -o $@ $(OBJ1) && echo -e "$(GREEN)[OK] $@ compiled !$(NORMAL)"

## Exercice 02
SRC2	=	ex02.c new.c point.c vertex.c
OBJ2	=	$(SRC2:.c=.o)
ex02:	$(OBJ2)
	@$(CC) -o $@ $(OBJ2) && echo -e "$(GREEN)[OK] $@ compiled !$(NORMAL)"

## Exercice 03
SRC3	=	ex03.c new.c point.c vertex.c
OBJ3	=	$(SRC3:.c=.o)
ex03:	$(OBJ3)
	@$(CC) -o $@ $(OBJ3) && echo -e "$(GREEN)[OK] $@ compiled !$(NORMAL)"

## Exercice 04
SRC4	=	new.c int.c float.c char.c ex04.c
OBJ4	=	$(SRC4:.c=.o)
ex04:	$(OBJ4)
	@$(CC) -o $@ $(OBJ4) && echo -e "$(GREEN)[OK] $@ compiled !$(NORMAL)"

## Exercice 05
SRC5	=	ex05.c array.c new.c int.c float.c char.c point.c
OBJ5	=	$(SRC5:.c=.o)
ex05:	$(OBJ5)
	@$(CC) -o $@ $(OBJ5) && echo -e "$(GREEN)[OK] $@ compiled !$(NORMAL)"

## Exercice 06
SRC6	=	new.c int.c float.c char.c list.c ex06.c
OBJ6	=	$(SRC6:.c=.o)
ex06:	$(OBJ6)
	@$(CC) -o $@ $(OBJ6) && echo -e "$(GREEN)[OK] $@ compiled !$(NORMAL)"

## Remove
RM		=	rm -f

clean:
	@make -C tests/ fclean
	@$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) && \
	echo -e "$(RED)[RM] all object files$(NORMAL)"

fclean:
	@make -C tests/ fclean
	@$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) && \
	echo -e "$(RED)[RM] all object files$(NORMAL)"
	@$(RM) ex01 ex02 ex03 ex04 ex05 ex06 && \
	echo -e "$(RED)[RM] ex01, ex02, ex03, ex04, ex05 and ex06$(NORMAL)"

## Phony
.PHONY: all re tests_run clean fclean
