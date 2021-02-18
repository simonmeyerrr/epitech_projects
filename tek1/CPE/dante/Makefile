##
## EPITECH PROJECT, 2017
## dante
## File description:
## Makefile
##

RM	=	rm -f

all:	compil

compil:
	$(MAKE) -C ./generator
	$(MAKE) -C ./solver
	cp generator/generator tournament/
	cp solver/solver tournament/

clean:
	$(MAKE) -C ./generator clean
	$(MAKE) -C ./solver clean

fclean:
	$(MAKE) -C ./generator fclean
	$(MAKE) -C ./solver fclean
	$(RM) tournament/generator tournament/solver

re:	fclean all

.PHONY:	all clean fclean re
