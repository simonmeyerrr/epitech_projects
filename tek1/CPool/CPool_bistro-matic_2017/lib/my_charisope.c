/*
** EPITECH PROJECT, 2017
** my_charisope
** File description:
** lib
*/

#include "../include/all.h"

int my_charisope(char c)
{
	if (c == '+' || c == '-' || c == '/' ||
	c == '*' || c == '%' || c == '(')
		return (1);
	return (0);
}
