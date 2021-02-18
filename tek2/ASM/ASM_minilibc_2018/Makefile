##
## EPITECH PROJECT, 2022
## ASM_minilibc_2018
## File description:
## Makefile
##

NAME	=	libasm.so

## Sources
SRC		=	src/memcpy.asm		\
			src/memmove.asm		\
			src/memset.asm		\
			src/rindex.asm		\
			src/strcasecmp.asm	\
			src/strchr.asm		\
			src/strcmp.asm		\
			src/strcspn.asm		\
			src/strlen.asm		\
			src/strncmp.asm		\
			src/strpbrk.asm		\
			src/strstr.asm

OBJ		=	$(SRC:.asm=.o)

## Compile
CC		=	ld
LDFLAGS	=	-shared -fPIC

NASM	=	nasm
ASMFLAG	=	-f elf64

## Remove
RM		=	rm -f

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.asm
	@echo -e "$(BLUE)[CC] $< -> $@$(NORMAL)"
	@$(NASM) $(ASMFLAG) -o $@ $<

clean:
	@make -C tests/ fclean
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@make -C tests/ fclean
	@$(RM) $(OBJ) $(RM_FILE) && \
    echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run: all
	@make -C tests/ tests_run

.PHONY: all clean fclean re tests_run
