/*
** EPITECH PROJECT, 2017
** getnextline_bootstrap
** File description:
** get_nb_calls.c
*/

#include "include/all.h"

int get_nb_calls(void)
{
	static int a = 0;
	a++;
	return (a);
}
