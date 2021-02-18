/*
** EPITECH PROJECT, 2017
** google_hash_code
** File description:
** l00p.c
*/

#include "all.h"

void move_start(vehicule_t *vehicule)
{
	ride_t *ride = vehicule->ride;

	if (vehicule->pos_raw != ride->start_raw) {
		if (vehicule->pos_raw > ride->start_raw)
			vehicule->pos_raw--;
		else
			vehicule->pos_raw++;
	} else if (vehicule->pos_col != ride->start_col) {
		if (vehicule->pos_col > ride->start_col)
			vehicule->pos_col--;
		else
			vehicule->pos_col++;
	} else {
		vehicule->status = 2;
		ride->status = 2;
	}
}

void move_end(vehicule_t *vehicule)
{
	ride_t *ride = vehicule->ride;

	if (vehicule->pos_raw != ride->end_raw) {
		if (vehicule->pos_raw > ride->end_raw)
			vehicule->pos_raw = vehicule->pos_raw - 1;
		else
			vehicule->pos_raw = vehicule->pos_raw + 1;
	} else if (vehicule->pos_col != ride->end_col) {
		if (vehicule->pos_col > ride->end_col)
			vehicule->pos_col = vehicule->pos_col - 1;
		else
			vehicule->pos_col = vehicule->pos_col + 1;
	}
}

void move(global_t *global)
{
	vehicule_t *vehicule = global->first_vehicule;

	while (vehicule) {
		if (vehicule->status == 1)
			move_start(vehicule);
		else if (vehicule->status == 2)
			move_end(vehicule);
		vehicule = vehicule->next;
	}
}
