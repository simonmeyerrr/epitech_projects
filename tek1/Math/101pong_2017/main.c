/*
** main 101pong_2017
** Meyer Simon
** Quirin Jean-Christophe
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void int_valid(char *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] < '0' || str[i] > '9')
			exit (84);
	}
}

void float_valid(char *str)
{
	int i = 0;
	int dot = 0;

	if (str[0] == '-')
		i = 1;
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			if (str[i] == '.' && dot == 0)
				dot = 1;
			else
				exit (84);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 8)
		exit (84);
	for (int i = 1 ; i < 7; i++)
		float_valid(av[i]);
	int_valid(av[7]);

	char **oui;
	double prev[3] = {strtod(av[1], oui), strtod(av[2], oui), strtod(av[3], oui)};
	double begin[3] = {strtod(av[4], oui), strtod(av[5], oui), strtod(av[6], oui)};
	int n = atoi(av[7]);
	if (n < 0)
		exit (84);

	double vector[3] = {begin[0] - prev[0], begin[1] - prev[1], begin[2] - prev[2]};
	double calc[3] = {begin[0] + (n * vector[0]), begin[1] + (n * vector[1]), begin[2] + (n * vector[2])};
	printf("The speed vector coordinates are :\n(%.2lf;%.2lf;%.2lf)\nAt time t+%d, ball coordinates will be :\n(%.2lf;%.2lf;%.2lf)\n",
	vector[0], vector[1], vector[2], n, calc[0], calc[1], calc[2]);

	if ((begin[2] > 0 && vector[2] >= 0) || (begin[2] < 0 && vector[2] <= 0)) {
		printf("The ball won't reach the bat.\n");
		return (0);
	}

	double vit1 = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
	double vit2 = sqrt(pow(vector[0], 2) + pow(vector[1], 2));
	double angle = acos(vit2/vit1) * (180 / M_PI);
	printf("The incidence angle is :\n%.2lf degrees\n", angle);

	return (0);
}
