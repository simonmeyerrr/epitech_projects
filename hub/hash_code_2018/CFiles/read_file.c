/*
** EPITECH PROJECT, 2017
** google_hash_code
** File description:
** read_file.c
*/

#include "all.h"

void disp_info(global_t *global)
{
	printf("GLOBAL:\n\nnb raw:\t%d\nnb col:\t%d\n\n", global->nb_raw, global->nb_col);
	printf("vehicule:\t%d\nnb ride:\t%d\n\n", global->vehicule, global->nb_ride);
	printf("bonus:\t\t%d\nmax_step:\t%ld\n", global->bonus, global->step_max);
}

void disp_ride(global_t *global)
{
	for (ride_t *tmp = global->first_ride ; tmp ; tmp = tmp->next) {
		printf("NB:%d\tstart: %d,%d", tmp->nb, tmp->start_raw, tmp->start_col);
		printf("\tend: %d,%d\t", tmp->end_raw, tmp->end_col);
		printf("early: %d\tfinish: %d\t", tmp->earliest, tmp->finish);
		printf("status: %d\n", tmp->status);
	}
	for (vehicule_t *tmp = global->first_vehicule ; tmp ; tmp = tmp->next) {
		printf("status: %d", tmp->status);
		printf("\tpos: %d,%d\n", tmp->pos_raw, tmp->pos_col);
	}
}

void verif_malloc(void *ptr)
{
	if (!ptr) {
		printf("Error while using malloc.\n");
		exit(MY_ERROR);
	}
}

char *get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char) * 50);
	int ret = 1;
	char c = 0;

	verif_malloc(buffer);
	memset(buffer, '\0', 50);
	while (ret == 1 && c != '\n') {
		ret = read(fd, &c, 1);
		if (ret == 1 && c != '\n' && strlen(buffer) < 50)
			buffer[strlen(buffer)] = c;
	}
	return (buffer);
}

char **str_to_tab(char *str)
{
	char **tab = malloc(sizeof(char*) * 7);
	int j = 0;
	int k = 0;

	verif_malloc(tab);
	for (int i = 0 ; i < 6 ; i++, j++, k = 0) {
		tab[i] = malloc(sizeof(char) * 12);
		verif_malloc(tab[i]);
		memset(tab[i], '\0', 12);
		while (str[j] >= '0' && str[j] <= '9') {
			tab[i][k] = str[j];
			j++;
			k++;
		}
	}
	tab[6] = NULL;
	return (tab);
}

void create_vehicule(global_t *global)
{
	vehicule_t *new = malloc(sizeof(*new));

	verif_malloc(new);
	new->status = 0;
	new->pos_raw = 0;
	new->pos_col = 0;
	new->nb_ride = 0;
	new->first_ride = NULL;
	new->last_ride = NULL;
	new->ride = NULL;
	new->next = NULL;
	new->prev = global->last_vehicule;
	if (!global->last_vehicule)
		global->first_vehicule = new;
	else
		global->last_vehicule->next = new;
	global->last_vehicule = new;
}

void first_info(global_t *global, int fd)
{
	char *str = get_next_line(fd);
	char **tab = str_to_tab(str);

	free(str);
	global->nb_raw = atoi(tab[0]);
	global->nb_col = atoi(tab[1]);
	global->vehicule = atoi(tab[2]);
	global->nb_ride = atoi(tab[3]);
	global->bonus = atoi(tab[4]);
	global->step_max = atol(tab[5]);
	global->step = 0;
	for (int i = 0 ; tab[i] ; i++)
		free(tab[i]);
	free(tab);
	global->first_vehicule = NULL;
	global->last_vehicule = NULL;
	global->first_ride = NULL;
	global->last_ride = NULL;
	for (int i = 0 ; i < global->vehicule ; i++)
		create_vehicule(global);
}

void add_ride(global_t *global, int fd, int i)
{
	char *str = get_next_line(fd);
	char **tab = str_to_tab(str);
	ride_t *ride = malloc(sizeof(*ride));

	verif_malloc(ride);
	ride->nb = i;
	ride->start_raw = atoi(tab[0]);
	ride->start_col = atoi(tab[1]);
	ride->end_raw = atoi(tab[2]);
	ride->end_col = atoi(tab[3]);
	ride->earliest = atol(tab[4]);
	ride->finish = atol(tab[5]);
	ride->status = 0;
	ride->next = NULL;
	ride->prev = global->last_ride;
	if (!global->last_ride)
		global->first_ride = ride;
	else
		global->last_ride->next = ride;
	global->last_ride = ride;
	free(str);
	for (int i = 0 ; tab[i] ; i++)
		free(tab[i]);
	free(tab);
}

global_t *read_file(char *path)
{
	global_t *global = malloc(sizeof(global_t));
	int fd = open(path, O_RDONLY);

	if (fd < 0) {
		printf("Can't open the file.\n");
		exit(MY_ERROR);
	}
	verif_malloc(global);
	first_info(global, fd);
	for (int i = 0 ; i < global->nb_ride ; i++)
		add_ride(global, fd, i);
	disp_info(global);
	disp_ride(global);
	return (global);
}
