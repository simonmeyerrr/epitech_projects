/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/proto.h"

char *infin_add(char *s1, char *s2)
{
	char *str;

	if ((s1[0] == '-' && s2[0] == '-') || (s1[0] != '-' && s2[0] != '-')) {
		if (s1[0] == '-')
			write(1, "-", 1);
		str = add_pos(s1, s2);
	}
	return (str);
}

int main(int ac, char **av)
{
	if (ac != 3) {
		write(2, "Invalid number of arguments\n", 28);
		return(84);
	}
	if (nb_isvalid(av[1]) == 0 || nb_isvalid(av[2]) == 0) {
		write(2, "Invalid argument\n", 17);
		return (84);
	}
	my_putrevstr(infin_add(av[1], av[2]));
	return(0);
}
