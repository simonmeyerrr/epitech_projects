/*
** EPITECH PROJECT, 2017
** getnextline_bootstrap
** File description:
** rget_nb_calls_init_9.c
*/

#include "include/all.h"

int get_nb_calls_init_9(void)
{
	static int a = 9;
	a++;
	return (a);
}
