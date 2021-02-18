/*
** EPITECH PROJECT, 2017
** doop2
** File description:
** calculator
*/

#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

int simple_op(int nbr1, int nbr2, char c)
{
	int result;

	if (c == '+')
		result = nbr1 + nbr2;
	if (c == '-')
		result = nbr1 - nbr2;
	if (c == '*')
		result = nbr1 * nbr2;
	if (result > 2147483647 || result < -2147483648) {
		write(1, "0\n", 2);
		return (84);
	} else {
		disp_nbr(result);
		return (result);
	}
}

int div_op(int nbr1, int nbr2, char c)
{
	int result;

	if (nbr2 == 0) {
		write(1, "Stop : division by zero\n", 24);
		return (84);
	}
	result = nbr1 / nbr2;
	if (result > 2147483647 || result < -2147483648) {
		write(1, "0\n", 2);
		return (84);
	} else {
		disp_nbr(result);
		return (result);
	}
}

int mod_op(int nbr1, int nbr2, char c)
{
	int result;

	if (nbr2 == 0) {
		write(1, "Stop : modulo by zero\n", 22);
		return (84);
	}
	result = nbr1 % nbr2;
	if (result > 2147483647 || result < -2147483648) {
		write(1, "0\n", 2);
		return (84);
	} else {
		disp_nbr(result);
		return (result);
	}
}

int thedisp(char c)
{
	write(1, &c, 1);
	return (0);
}

int disp_nbr(int nb)
{
	int modulo;
	if (nb == -2147483648) {
		write(1, "-2147483648\n", 12);
		return (0);
	}
	if (nb < 0) {
		nb = nb * -1;
		write(1, "-", 1);
	}
	if (nb >= 10) {
		modulo = nb % 10;
		nb = (nb - modulo) / 10;
		disp_nbr(nb);
		thedisp(modulo + 48);
	} else {
		thedisp(nb + 48);
		return (0);
	}
	return (0);
}
