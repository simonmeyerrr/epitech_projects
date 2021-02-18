##
## EPITECH PROJECT, 2022
## PSU_2018_nmobjdump
## File description:
## Makefile
##

all: nm objdump

nm:
	@make -C nm/

objdump:
	@make -C objdump/

clean:
	@make -C nm/ clean
	@make -C objdump/ clean

fclean:
	@make -C nm/ fclean
	@make -C objdump/ fclean

re:
	@make -C nm/ re
	@make -C objdump/ re

tests_run:
	@make -C tests/ tests_run

.PHONY: all clean fclean re tests_run nm objdump
