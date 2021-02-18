/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** player.c
*/

#include "all.h"

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

int check_line(char *str, int *param, int *stick, int *error)
{
	int nb;

	if (!str) {
		*error = 1;
		return (-1);
	}
	nb = my_getnbr(str);
	if (nb < 0)
		my_disp("Error: invalid input (positive number expected)\n", 1);
	if (nb == 0 || nb > param[0]) {
		my_disp("Error: this line is out of range\n", 1);
		nb = -1;
	}
	free(str);
	return (nb);
}

int check_match(char *str, int *param, int *stick, int *error)
{
	int nb;

	if (!str) {
		*error = 1;
		return (-1);
	}
	nb = my_getnbr(str);
	if (nb < 0)
		my_disp("Error: invalid input (positive number expected)\n", 1);
	if (nb == 0)
		my_disp("Error: you have to remove at least one match\n", 1);
	if (nb > param[1]) {
		my_disp("Error: you cannot remove more than ", 1);
		my_putnbr(param[1]);
		my_disp(" matches per turn\n", 1);
	} else if (nb > stick[param[2] - 1])
		my_disp("Error: not enough matches on this line\n", 1);
	free(str);
	return ((nb > param[1] || nb > stick[param[2] - 1]) ? (-1) : (nb));
}

int *get_line_match(int *param, int *stick, int *error)
{
	int *pos = malloc(sizeof(int) * 2);

	if (*error != 0 || !pos)
		return (pos);
	my_disp("Line: ", 1);
	pos[0] = check_line(get_next_line(0), param, stick, error);
	if (pos[0] <= 0) {
		my_free(pos);
		return (get_line_match(param, stick, error));
	}
	param[2] = pos[0];
	my_disp("Matches: ", 1);
	pos[1] = check_match(get_next_line(0), param, stick, error);
	if (pos[1] <= 0) {
		my_free(pos);
		return (get_line_match(param, stick, error));
	}
	return (pos);
}

int turn_player(int *param, int *stick, int *error)
{
	int *pos;

	my_disp("\nYour turn:\n", 1);
	pos = get_line_match(param, stick, error);
	if (*error != 0 || pos == NULL){
		*error = 1;
		my_free(pos);
		return (2);
	}
	my_disp("Player removed ", 1);
	my_putnbr(pos[1]);
	my_disp(" match(es) from line ", 1);
	my_putnbr(pos[0]);
	my_disp("\n", 1);
	stick[pos[0] - 1] -= pos[1];
	disp_matchstick(param, stick);
	my_free(pos);
	return (2);
}
