/*
** EPITECH PROJECT, 2017
** google_hash_code
** File description:
** main.c
*/

#include "all.h"

int main(int ac, char **av)
{
	if (ac != 2) {
		printf("Invalid number of argument.\n");
		return (MY_ERROR);
	}
	global_t *global = read_file(av[1]);
	//sort_ride(global);
	loop(global);
	FILE *fd = fopen("result", "w+");
	write_result(global, fd);
	return (MY_SUCCESS);
}
