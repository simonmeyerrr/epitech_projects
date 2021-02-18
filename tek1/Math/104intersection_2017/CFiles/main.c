/*
** EPITECH PROJECT, 2017
** 104intersection_2017
** File description:
** main.c
*/

#include "all.h"

void end_display(int number, double *sol)
{
	if (number == 0)
		printf("No intersection point.\n");
	if (number == 1) {
		printf("1 intersection point :\n(%.3lf", sol[0]);
		printf(", %.3lf, %.3lf)\n", sol[1], sol[2]);
	}
	if (number == 2) {
		printf("2 intersection points :\n(%.3lf, ", sol[0]);
		printf("%.3lf, %.3lf)\n(", sol[1], sol[2]);
		printf("%.3lf, %.3lf, %.3lf)\n", sol[3], sol[4], sol[5]);
	}
	if (number > 2)
		printf("There is an infinite number of intersection points.\n");
	exit(0);
}

void equation(double a, double b, double c, double *t)
{
	double delta = pow(b, 2) - (4 * a * c);

	if (delta < 0) {
		t[0] = 0;
		return;
	}
	if (delta == 0) {
		t[1] = (-b) / (2.0 * a);
		t[0] = 1;
		return;
	}
	t[0] = 2;
	t[1] = (-b + sqrt(delta)) / (2.0 * a);
	t[2] = (-b - sqrt(delta)) / (2.0 * a);
	return;
}

static int is_nbr_valid(char *nbr, char *str, int case_nbr)
{
	int i = ((nbr[0] == '-') ? (1) : (0));

	while (nbr[i] != '\0') {
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	if (case_nbr == 8 && nbr[0] == '-')
		return (0);
	if (case_nbr == 8 && atoi(nbr) <= 0)
		return (0);
	if (case_nbr == 8 && atoi(nbr) >= 360 && str[0] == '3')
		return (0);
	return (1);
}

static int error_management(int ac, char **av)
{
	if (ac != 9) {
		write(2, "Invalid number of arguments.\n", 29);
		return (EXIT_ERROR);
	}
	if (strcmp(av[1], "1") != 0 && strcmp(av[1], "2") != 0 &&
	strcmp(av[1], "3") != 0) {
		write(2, "Invalid type of object.\n", 24);
		return (EXIT_ERROR);
	}
	for (int i = 2 ; i < 9 ; i++) {
		if (is_nbr_valid(av[i], av[1], i) == 0) {
			write(2, "Invalid number.\n", 16);
			return (EXIT_ERROR);
		}
	}
}

int main(int ac, char **av)
{
	int obj;

	if (error_management(ac, av) == EXIT_ERROR)
		return (EXIT_ERROR);
	(strcmp(av[1], "1") == 0) ? (obj = 1) : (0);
	(strcmp(av[1], "2") == 0) ? (obj = 2) : (0);
	(strcmp(av[1], "3") == 0) ? (obj = 3) : (0);
	(obj == 1) ? (printf("sphere of radius %s\nstraight", av[8])) : (0);
	(obj == 2) ? (printf("cylinder of radius %s\nstraight", av[8])) : (0);
	(obj == 3) ? (printf("cone of %s degree angle\nstraight", av[8])) : (0);
	printf(" line going through the (%s,%s,%s) point", av[2], av[3], av[4]);
	printf(" and of direction vector (%s,%s,%s)\n", av[5], av[6], av[7]);
	(obj == 1) ? sphere(av) : ((obj == 2) ? cylinder(av) : cone(av));
	return (EXIT_SUCCESS);
}
