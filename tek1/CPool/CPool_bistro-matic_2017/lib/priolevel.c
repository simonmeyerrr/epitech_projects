/*
** EPITECH PROJECT, 2017
** priolevel.c
** File description:
** return priority's level of an operator
*/

#include "../include/all.h"

int priolevel(char c)
{
	if (c == '*' || c == '/' || c == '%')
		return (3);
	if (c == '+' || c == '-')
		return (2);
	return (0);
}
