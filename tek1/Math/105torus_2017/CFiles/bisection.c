/*
** EPITECH PROJECT, 2017
** 105torus_2017
** File description:
** bisection.c
*/

#include "all.h"

static long double get_result(long double x, long double *coef)
{
	long double result = 0;

	for (int i = 0 ; i < 5 ; i++)
		result += coef[i] * pow(x, i);
	return (result);
}

static void copy_str(char *s, char *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++)
		s[i] = str[i];
}

static long double display_x(long double x, int prec, long double *coef, char *s)
{
	long double result = get_result(x, coef);
	char *str = malloc(sizeof(char*) * (prec + 3));
	int a;
	long double b;
	int len = 0;

	sprintf(str, "%llf", x);
	a = x * pow(10, prec);
	b = a;
	str[prec + 2] = '\0';
	while (str[len] != '\0')
		len++;
	if (b == x * pow(10, prec)) {
		for (int i = len - 1; str[i] == '0' ; i--)
			str[i] = '\0';
	}
	if (s != NULL && strcmp(str, s) == 0)
		return (0.0);
	printf("x = %s\n", str);
	copy_str(s, str);
	free(str);
	return (result);
}

static void recur_bisection(long double *coef, int *prec, long double *a,
long double *b, char *s)
{
	long double mid = (a[0] + b[0]) / 2.0;
	long double res = display_x(mid, prec[0], coef, s);

	prec[1] += 1;
	if (res == 0.0 || prec[1] > 50)
		return;
	if ((res < 0 && a[1] < 0) || (res > 0 && a[1] > 0)) {
		a[0] = mid;
		a[1] = res;
	} else {
		b[0] = mid;
		b[1] = res;
	}
	recur_bisection(coef, prec, a, b, s);
}

void bisection(char **av)
{
	long double coef[5] = {atoi(av[2]), atoi(av[3]), atoi(av[4]),
	atoi(av[5]), atoi(av[6])};
	int prec[2] = {atoi(av[7]), 0};
	long double a[2] = {0, get_result(0, coef)};
	long double b[2] = {1, get_result(1, coef)};
	char *s = malloc(sizeof(char*) * 30);

	recur_bisection(coef, prec, a, b, s);
	free(s);
}
