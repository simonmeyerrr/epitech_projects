/*
** EPITECH PROJECT, 2017
** dante_generator
** File description:
** main.c
*/

#include "../include/all.h"

static int is_nb_valid(char *str)
{
	for (int i = 0 ; str && str[i] ; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

static int manage_arg(int ac, char **av)
{
	if (ac != 4 && ac != 3) {
		my_putstr_fd("Invalid number of arguments.\n", 2);
		return (1);
	}
	if (is_nb_valid(av[1]) != 1) {
		my_putstr_fd(av[1], 2);
		my_putstr_fd(" : Invalid number.\n", 2);
		return (1);
	} else if (is_nb_valid(av[2]) != 1) {
		my_putstr_fd(av[2], 2);
		my_putstr_fd(" : Invalid number.\n", 2);
		return (1);
	}
	if (ac == 4 && my_strcmp(av[3], "perfect") != 0) {
		my_putstr_fd(av[3], 2);
		my_putstr_fd(" : Invalid argument.\n", 2);
		return (1);
	}
	return (0);
}

static void display_help(char *path, int fd)
{
	my_putstr_fd("\nUSAGE:\n\t", fd);
	my_putstr_fd(path, fd);
	my_putstr_fd(" width height [perfect]\n\n\twidth\t\tint which define t"
	"he width of the maze.\n\theight\t\tint which define the height of the"
	" maze.\n\t[perfect]\twrite perfect if you want the maze to be perfect"
	"(def: imperfect).\n\n", fd);
}

int main(int ac, char **av)
{
	int error = manage_arg(ac, av);

	if (error != 0) {
		display_help(av[0], 2);
		return (MY_ERROR);
	}
	if (ac == 4)
		create_maze(my_getnbr(av[1]), my_getnbr(av[2]), 1);
	else
		create_maze(my_getnbr(av[1]), my_getnbr(av[2]), 0);
	return (MY_SUCCESS);
}
