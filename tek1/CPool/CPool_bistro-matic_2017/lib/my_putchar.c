/*
** EPITECH PROJECT, 2017
** putchar
** File description:
** oui
*/

#include "../include/all.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
