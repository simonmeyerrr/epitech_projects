/*
** EPITECH PROJECT, 2017
** 104intersection_2017
** File description:
** object.c
*/

#include "all.h"

void sphere(char **av)
{
	double point[3] = {atof(av[2]), atof(av[3]), atof(av[4])};
	double vector[3] = {atof(av[5]), atof(av[6]), atof(av[7])};
	double parameter = atof(av[8]);
	double a = pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2);
	double b = (2.0 * vector[0] * point[0]) + (2.0 * vector[1] * point[1]) +
	(2.0 * vector[2] * point[2]);
	double c = pow(point[0], 2) + pow(point[1], 2) + pow(point[2], 2)-
	pow(parameter, 2);
	double *t = malloc(sizeof(double*) * 3);
	double *solution = malloc(sizeof(double*) * 6);

	(a == 0) ? (end_display(0, NULL)) : (equation(a, b, c, t));
	(t[0] > 0) ? (solution[0] = point[0] + (t[1] * vector[0])) : (0);
	(t[0] > 0) ? (solution[1] = point[1] + (t[1] * vector[1])) : (0);
	(t[0] > 0) ? (solution[2] = point[2] + (t[1] * vector[2])) : (0);
	(t[0] > 1) ? (solution[3] = point[0] + (t[2] * vector[0])) : (0);
	(t[0] > 1) ? (solution[4] = point[1] + (t[2] * vector[1])) : (0);
	(t[0] > 1) ? (solution[5] = point[2] + (t[2] * vector[2])) : (0);
	end_display(t[0], solution);
}

static void special_cylinder(double *point, double *vec, double par, double a)
{
	if (a == 0)
		end_display(0, NULL);
}

void cylinder(char **av)
{
	double point[3] = {atof(av[2]), atof(av[3]), atof(av[4])};
	double vector[3] = {atof(av[5]), atof(av[6]), atof(av[7])};
	double parameter = atof(av[8]);
	double a = pow(vector[0], 2) + pow(vector[1], 2);
	double b = (2.0 * vector[0] * point[0]) + (2.0 * vector[1] * point[1]);
	double c = pow(point[0], 2) + pow(point[1], 2) - pow(parameter, 2);
	double *t = malloc(sizeof(double*) * 3);
	double *solution = malloc(sizeof(double*) * 6);

	special_cylinder(point, vector, parameter, a);
	equation(a, b, c, t);
	(t[0] > 0) ? (solution[0] = point[0] + (t[1] * vector[0])) : (0);
	(t[0] > 0) ? (solution[1] = point[1] + (t[1] * vector[1])) : (0);
	(t[0] > 0) ? (solution[2] = point[2] + (t[1] * vector[2])) : (0);
	(t[0] > 1) ? (solution[3] = point[0] + (t[2] * vector[0])) : (0);
	(t[0] > 1) ? (solution[4] = point[1] + (t[2] * vector[1])) : (0);
	(t[0] > 1) ? (solution[5] = point[2] + (t[2] * vector[2])) : (0);
	end_display(t[0], solution);
}

static int spe_cone(double * point, double *vec, double par, double a)
{
	if (a == 0)
		end_display(0, NULL);
	return (0);
}

void cone(char **av)
{
	double point[3] = {atof(av[2]), atof(av[3]), atof(av[4])};
	double vector[3] = {atof(av[5]), atof(av[6]), atof(av[7])};
	double angle = atof(av[8]) * (M_PI / 180.0);
	double a = pow(vector[0], 2) + pow(vector[1], 2) - (pow(vector[2], 2) *
	pow((tan(angle)), 2));
	double b = (2.0 * vector[0] * point[0]) + (2.0 * vector[1] * point[1]) -
	(2.0 * vector[2] * point[2] * pow((tan(angle)), 2));
	double c = pow(point[0], 2) + pow(point[1], 2) - (pow(point[2], 2) *
	pow((tan(angle)), 2));
	double *t = malloc(sizeof(double*) * 3);
	double *solution = malloc(sizeof(double*) * 6);

	(spe_cone(point, vector, angle, a) == 0) ? equation(a, b, c, t) : (0);
	(t[0] > 0) ? (solution[0] = point[0] + (t[1] * vector[0])) : (0);
	(t[0] > 0) ? (solution[1] = point[1] + (t[1] * vector[1])) : (0);
	(t[0] > 0) ? (solution[2] = point[2] + (t[1] * vector[2])) : (0);
	(t[0] > 1) ? (solution[3] = point[0] + (t[2] * vector[0])) : (0);
	(t[0] > 1) ? (solution[4] = point[1] + (t[2] * vector[1])) : (0);
	(t[0] > 1) ? (solution[5] = point[2] + (t[2] * vector[2])) : (0);
	end_display(t[0], solution);
}
