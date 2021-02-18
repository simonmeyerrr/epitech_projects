##
## EPITECH PROJECT, 2018
## cpp_d02a_2018
## File description:
## Makefile
##

all:	tests_run

tests_run:
	@make -C ./tests/ re && ./tests/unit_tests && make -C ./tests/ clean

clean:
	@make -C ./tests/ clean

fclean:
	@make -C ./tests/ fclean

re: fclean all

.PHONY: all tests_run clean fclean re
