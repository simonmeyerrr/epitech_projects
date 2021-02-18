/*
** EPITECH PROJECT, 2017
** doop1
** File description:
** calculator
*/

#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

int extract_num2(char const *str, int i, int neg)
{
	int nb = 0;

	while (str[i] >= '0' && str[i] <= '9') {
		if ((nb >= 214748364 && str[i] > '8') ||
		    (nb >= 214748364 && str[i] > '7' && neg % 2 == 0) ||
		    (nb >= 1000000000))
			return (0);
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb);
}

int extract_num(char const *str)
{
	int i = 0;
	int neg = 0;
	int nb;

	if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		return (0);
	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			neg++;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	nb = extract_num2(str, i, neg);
	if (neg % 2 != 0 && nb != 0)
		nb = nb * -1;
	return (nb);
}

int operation(int ac, char **av)
{
	int nbr1 = extract_num(av[1]);
	int nbr2 = extract_num(av[3]);
	int result;

	if (av[2][0] != '+' && av[2][0] != '-' && av[2][0] != '*' &&
	    av[2][0] != '/' && av[2][0] != '%') {
		write(1, "0\n", 2);
		return (0);
	}
	if (av[2][0] == '+' || av[2][0] == '-' || av[2][0] == '*')
		result = simple_op(nbr1, nbr2, av[2][0]);
	if (av[2][0] == '/')
		result = div_op(nbr1, nbr2, av[2][0]);
	if (av[2][0] == '%')
		result = mod_op(nbr1, nbr2, av[2][0]);
	write(1, "\n", 1);
	return (result);
}

int main(int argc, char **argv)
{
	int result;

	if (argc != 4) {
		write(1, "0\n", 2);
		return (84);
	}
	result = operation(argc, argv);
	if (result == 84)
		return (84);
	return (0);
}
