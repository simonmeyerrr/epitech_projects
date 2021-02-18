/*
** EPITECH PROJECT, 2017
** google_hash_code
** File description:
** l00p.c
*/

#include "all.h"

void refresh(global_t *global)
{
	vehicule_t *vehicule = global->first_vehicule;
	ride_t *ride;

	while (vehicule) {
		ride = vehicule->ride;
		if (vehicule->status == 2 && ride->end_raw == vehicule->pos_raw
		&& ride->end_col == vehicule->pos_col) {
			vehicule->status = 0;
			vehicule->nb_ride = vehicule->nb_ride + 1;
			ride->status = 3;
			vehicule->ride = NULL;
			if (ride->prev)
				ride->prev->next = ride->next;
			if (ride->next)
				ride->next->prev = ride->prev;
			ride->prev = vehicule->last_ride;
			if (vehicule->last_ride)
				vehicule->last_ride->next = ride;
			else
				vehicule->first_ride = ride;
			vehicule->last_ride = ride;
		}
		if (vehicule->status == 1 && ride->start_raw == vehicule->pos_raw
		&& ride->start_col == vehicule->pos_col && ride->earliest <= global->step) {
			vehicule->status = 2;
			ride->status = 2;
		}
		vehicule = vehicule->next;
	}
}

int vehicule_dispo(global_t *global)
{
	vehicule_t *vehicule = global->first_vehicule;

	while (vehicule) {
		if (vehicule->status == 0)
			return (1);
		vehicule = vehicule->next;
	}
	return (0);
}

void search_ride(vehicule_t *vehic, global_t *global)
{
	for (ride_t *tmp = global->first_ride ; tmp ; tmp = tmp->next) {
		if (tmp->status == 0) {
			tmp->status = 1;
			vehic->status = 1;
			vehic->ride = tmp;
			return;
		}
	}
}

void algo(global_t *global)
{
	for (vehicule_t *tmp = global->first_vehicule ; tmp ; tmp = tmp->next) {
		if (tmp->status == 0)
			search_ride(tmp, global);
	}
}

int loop(global_t *global)
{
	while (global->step < global->step_max) {
		printf("\n\n");
		disp_ride(global);
		algorithme(global);
		move(global);
		refresh(global);
		global->step = global->step + 1;
	}
}
