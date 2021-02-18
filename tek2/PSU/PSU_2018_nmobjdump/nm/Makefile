##
## EPITECH PROJECT, 2022
## PSU_2018_nmobjdump
## File description:
## Makefile
##

NAME	=	my_nm

## Sources
SRC		=	src/main.c	\
			src/my_nm.c	\
			src/prepare_elf.c

OBJ		=	$(SRC:.c=.o)

## Compile
CC		=	gcc
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
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && cp $(NAME) ../ && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.c
	@echo -e "$(BLUE)[CC] $< -> $@$(NORMAL)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) ../$(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run:
	@make -C ../ tests_run

.PHONY: all clean fclean re tests_run
