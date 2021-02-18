/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** robot.c
*/

#include "all.h"

void algo_one(int *pos, int *param, int *stick)
{
	int line = 0;

	for (int i = 0 ; i < param[0] ; i++) {
		if (stick[i] > 0)
			line = i;
	}
	pos[0] = line;
	if (stick[line] == 1 || stick[line] > 1 + param[1])
		pos[1] = 1;
	if (stick[line] > 1 && stick[line] <= 1 + param[1])
		pos[1] = stick[line] - 1;
}

void algo_more(int *pos, int *param, int *stick)
{
	for (int i = param[0] - 1 ; i >= 0 ; i--) {
		if (stick[i] > 0) {
			pos[0] = i;
			pos[1] = (stick[i] < param[1]) ?
			(stick[i]) : (param[1]);
			return;
		}
	}
}

int *ai_algo(int *param, int *stick)
{
	int *pos = malloc(sizeof(int) * 2);
	int unempty = 0;

	for (int i = 0 ; i < param[0] ; i++) {
		if (stick[i] > 0)
			unempty++;
	}
	if (unempty == 1)
		algo_one(pos, param, stick);
	else
		algo_more(pos, param, stick);
	return (pos);
}

int turn_robot(int *param, int *stick, int *error)
{
	int *pos;

	my_disp("\nAI's turn...\n", 1);
	pos = ai_algo(param, stick);
	my_disp("AI removed ", 1);
	my_putnbr(pos[1]);
	my_disp(" match(es) from line ", 1);
	my_putnbr(pos[0] + 1);
	my_disp("\n", 1);
	stick[pos[0]] -= pos[1];
	disp_matchstick(param, stick);
	if (pos)
		free(pos);
	return (1);
}
