/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** main.c
*/

#include "all.h"

void disp_matrice(double **matrice)
{
	char *size = malloc(sizeof(char*) * 100);
	int space_nb;

	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			sprintf(size, "%.2lf", matrice[i][j]);
			printf("%s", size);
			space_nb = 11 - strlen(size);
			for (int k = 0 ; k < space_nb  && j < 2; k++) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

double **init_matrice(void)
{
	double **matrice = malloc(sizeof(double**) * 3);
	double *mat1 = malloc(sizeof(double*) * 3);
	mat1[0] = 1;
	mat1[1] = 0;
	mat1[2] = 0;
	matrice[0] = mat1;
	double *mat2 = malloc(sizeof(double*) * 3);
	mat2[0] = 0;
	mat2[1] = 1;
	mat2[2] = 0;
	matrice[1] = mat2;
	double *mat3 = malloc(sizeof(double*) * 3);
	mat3[0] = 0;
	mat3[1] = 0;
	mat3[2] = 1;
	matrice[2] = mat3;
	return (matrice);
}

int main(int ac, char **av)
{
	if (error_management(ac, av) == 1) {
		write(2, "Invalids arguments.\n", 20);
		return (84);
	}
	double **matrice = init_matrice();
	double **matrice2;
	for (int i = 3 ; i < ac ; i++) {
		if (strcmp(av[i], "-t") == 0) {
			matrice2 = translation(av[i + 1], av[i + 2]);
			i += 2;
		} else if (strcmp(av[i], "-h") == 0) {
			matrice2 = homothety(av[i + 1], av[i + 2], 0);
			i += 2;
		} else if (strcmp(av[i], "-r") == 0) {
			matrice2 = rotation(av[i + 1], 0);
			i += 1;
		} else if (strcmp(av[i], "-s") == 0) {
			matrice2 = symmetry(av[i + 1]);
			i += 1;
		}
		matrice = multiplication(matrice, matrice2);
	}
	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			if (matrice[i][j] < 0 && matrice[i][j] > -0.000001)
				matrice[i][j] = 0;
		}
	}
	disp_matrice(matrice);
	double nb1 = atof(av[1]);
	double nb2 = atof(av[2]);
	printf("(%s,%s) => (%.2lf,%.2lf)\n", av[1], av[2],
	(nb1 * matrice[0][0] + nb2 * matrice[0][1] + matrice[0][2]),
	(nb1 * matrice[1][0] + nb2 * matrice[1][1] + matrice[1][2]));
	return (0);
}
