/*
** EPITECH PROJECT, 2017
** printf_pc.c
** File description:
** print pourcent
*/

#include <stdarg.h>
#include <unistd.h>

int printf_pourcent(va_list list)
{
	write(1, "%", 1);
	return (1);
}
