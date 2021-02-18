##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile
##

all:	core games graphicals

core:
	@make --silent -C core/

games:
	@make --silent -C games/

graphicals:
	@make --silent -C lib/

clean:
	@make --silent -C core/ clean
	@make --silent -C games/ clean
	@make --silent -C lib/ clean
	@make --silent -C tests/ clean

fclean:
	@make --silent -C core/ fclean
	@make --silent -C games/ fclean
	@make --silent -C lib/ fclean
	@make --silent -C tests/ fclean

re:
	@make --silent -C core/ re
	@make --silent -C games/ re
	@make --silent -C lib/ re

tests_run:
	@make --silent -C tests/ tests_run

.PHONY: all core games graphicals clean fclean re tests_run
