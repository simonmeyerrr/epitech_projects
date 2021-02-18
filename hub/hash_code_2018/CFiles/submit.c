/*
** EPITECH PROJECT, 2017
** google_hash_code
** File description:
** main.c
*/

#include "all.h"

void write_result(global_t *global, FILE *fd)
{
	vehicule_t *vehic = global->first_vehicule;

	while (vehic) {
		fprintf(fd, "%d", vehic->nb_ride);
		for (ride_t *tmp = vehic->first_ride ; tmp ; tmp = tmp->next)
			fprintf(fd, " %d", tmp->nb);
		fprintf(fd, "\n");
		vehic = vehic->next;
	}
}
