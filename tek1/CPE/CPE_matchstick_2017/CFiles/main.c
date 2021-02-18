/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** main.c
*/

#include "all.h"

void disp_matchstick(int *param, int *stick)
{
	for (int i = 0 ; i < param[0] * 2 + 1 ; i++)
		write(1, "*", 1);
	write(1, "\n", 1);
	for (int j = 0 ; j < param[0] ; j++) {
		write(1, "*", 1);
		for (int i = 0 ; param[0] - j - i > 1 ; i++)
			write(1, " ", 1);
		for (int i = 0 ; i < stick[j] ; i++)
			write(1, "|", 1);
		for (int i = 0 ; param[0] - j - i > 1 ; i++)
			write(1, " ", 1);
		for (int i = 0 ; i < j * 2 + 1 - stick[j] ; i++)
			write(1, " ", 1);
		write(1, "*\n", 2);
	}
	for (int i = 0 ; i < param[0] * 2 + 1 ; i++)
		write(1, "*", 1);
	write(1, "\n\n", 1);
}

static int check_valid(int ac, char **av)
{
	if (ac != 3)
		return (0);
	if (my_getnbr(av[1]) > 99 || my_getnbr(av[1]) < 1 ||
	my_getnbr(av[2]) < 1)
		return (0);
	return (1);
}

static int stick_is_finished(int *param, int *stick)
{
	for (int i = 0 ; i < param[0] ; i++) {
		if (stick[i] > 0)
			return (0);
	}
	return (1);
}

static int matchstick(char **av, int *error)
{
	int param[3] = {my_getnbr(av[1]), my_getnbr(av[2]), 0};
	int *stick = malloc(sizeof(int) * param[0]);
	int turn = 1;

	if (!stick)
		*error = 1;
	for (int i = 0 ; *error == 0 && i < param[0] ; i++)
		stick[i] = 1 + (2 * i);
	disp_matchstick(param, stick);
	while (stick_is_finished(param, stick) == 0 && *error == 0) {
		if (turn == 1 && *error == 0)
			turn = turn_player(param, stick, error);
		else if (turn == 2 && *error == 0)
			turn = turn_robot(param, stick, error);
	}
	if (turn == 1 && *error == 0)
		my_disp("I lost... snif... but I'll get you next time!!\n", 1);
	else if (turn == 2 && *error == 0)
		my_disp("You lost, too bad...\n", 1);
	return (turn);
}

int main(int ac, char **av)
{
	int error = 0;
	int ret;

	if (check_valid(ac, av) == 1) {
		ret = matchstick(av, &error);
		if (error == 1) {
			error = 0;
			ret = 0;
		}
	} else {
		my_disp("Invalid arguments.\n", 2);
		error = 1;
	}
	return ((error == 0) ? (ret) : (EXIT_ERROR));
}
