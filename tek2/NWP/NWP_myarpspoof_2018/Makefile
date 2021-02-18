##
## EPITECH PROJECT, 2022
## NWP_myarpspoof_2018
## File description:
## Makefile
##

NAME	=	myARPspoof

## Sources
SRC		=	src/main.c	\
			src/get_args.c	\
			src/utils.c		\
			src/get_mac_address.c	\
			src/get_headers.c	\
			src/get_ip.c	\
			src/do_arp.c

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
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	printf "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)\n"

%.o: %.c
	@printf "$(BLUE)[CC] $< -> $@$(NORMAL)\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ) $(RM_FILE) && \
	printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"

fclean:
	@$(RM) $(OBJ) $(RM_FILE) && \
	printf "$(RED)[RM] $(NAME)'s object files$(NORMAL)\n"
	@$(RM) $(NAME) && printf "$(RED)[RM] $(NAME)$(NORMAL)\n"

re: fclean all

.PHONY: all clean fclean re
