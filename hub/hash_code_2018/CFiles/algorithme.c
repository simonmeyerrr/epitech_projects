/*
** EPITECH PROJECT, 2017
** google_hash_code
** File description:
** main.c
*/

#include "all.h"

vehicule_t *isCar_free(global_t *global)
{
	for (vehicule_t *vt = global->first_vehicule; vt ;vt = vt->next) {
		if (vt->status == 0) {
			return (vt);
		}
	}
	return (NULL);
}

ride_t *isRide_free(global_t *global)
{
	for (ride_t *rt = global->first_ride; rt; rt = rt->next) {
		if (rt->status == 0) {
			return (rt);
		}
	}
	return (NULL);
}

void algorithme(global_t *global, vehicule_t *vehicule, ride_t *ride)
{
	ride_t *v1 = isRide_free(global);
	if (!v1)
		return;
	vehicule_t *v2 = isCar_free(global);
	if (!v2)
		return;
	v2->ride = v1;
	v2->status = 1;
	v1->status = 1;
}
