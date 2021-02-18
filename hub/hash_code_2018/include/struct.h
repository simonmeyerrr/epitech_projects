/*
** EPITECH PROJECT, 2017
** google_hash_code
** File description:
** struct.h
*/

typedef struct ride
{
	int nb;

	int start_raw;
	int start_col;

	int end_raw;
	int end_col;

	long earliest;
	long finish;

	int status;

	struct ride *next;
	struct ride *prev;
} ride_t;

typedef struct vehicule
{
	int status;

	int pos_raw;
	int pos_col;

	ride_t *ride;

	int nb_ride;
	ride_t *first_ride;
	ride_t *last_ride;

	struct vehicule *next;
	struct vehicule *prev;
} vehicule_t;

typedef struct global
{
	int nb_raw;
	int nb_col;

	int vehicule;
	int nb_ride;

	int bonus;
	long step;
	long step_max;

	vehicule_t *first_vehicule;
	vehicule_t *last_vehicule;

	ride_t *first_ride;
	ride_t *last_ride;
} global_t;
