##
## EPITECH PROJECT, 2022
## cpp_rush2_2018
## File description:
## Makefile
##

RM	=	rm -f

all:
	@make -C ex1/ all && cp ex1/elves .
	@make -C ex2/ all && cp ex2/santa .

clean:
	@make -C ex1/ clean ; make -C ex2/ clean ; make -C tests/ clean

fclean:
	@make -C ex1/ fclean ; make -C ex2/ fclean ; make -C tests/ fclean
	@$(RM) elves santa

re: fclean all

tests_run:
	@make -C tests/ re && ./tests/unit_tests && make -C tests/ clean

.PHONY: all clean fclean re tests_run
