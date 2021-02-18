/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** operation.c
*/

#include "all.h"

double **multiplication(double **mat2, double **mat1)
{
	double **matrice = malloc(sizeof(double**) * 3);
	double *matr1 = malloc(sizeof(double*) * 3);
	double *matr2 = malloc(sizeof(double*) * 3);
	double *matr3 = malloc(sizeof(double*) * 3);
	matrice[0] = matr1;
	matrice[1] = matr2;
	matrice[2] = matr3;
	double nb;
	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			nb = 0;
			for (int k = 0 ; k < 3 ; k++) {
				nb += mat1[i][k] * mat2[k][j];
			}
			matrice[i][j] = nb;
		}
	}
	return (matrice);
}

double** translation(char* nb1, char* nb2)
{
	printf("Translation by the vector (%s, %s)\n", nb1, nb2);
	double i = atof(nb1);
	double j = atof(nb2);
	double **trans = malloc(sizeof(double**) * 3);
	double *trans1 = malloc(sizeof(double*) * 3);
	trans1[0] = 1;
	trans1[1] = 0;
	trans1[2] = i;
	trans[0] = trans1;
	double *trans2 = malloc(sizeof(double*) * 3);
	trans2[0] = 0;
	trans2[1] = 1;
	trans2[2] = j;
	trans[1] = trans2;
	double *trans3 = malloc(sizeof(double*) * 3);
	trans3[0] = 0;
	trans3[1] = 0;
	trans3[2] = 1;
	trans[2] = trans3;
	return (trans);
}

double** homothety(char* nb1, char* nb2, int sym)
{
	if (sym == 0)
		printf("Homothety by the ratios %s and %s\n", nb1, nb2);
	double i = atof(nb1);
	double j = atof(nb2);
	double **homo = malloc(sizeof(double**) * 3);
	double *homo1 = malloc(sizeof(double*) * 3);
	homo1[0] = i;
	homo1[1] = 0;
	homo1[2] = 0;
	homo[0] = homo1;
	double *homo2 = malloc(sizeof(double*) * 3);
	homo2[0] = 0;
	homo2[1] = j;
	homo2[2] = 0;
	homo[1] = homo2;
	double *homo3 = malloc(sizeof(double*) * 3);
	homo3[0] = 0;
	homo3[1] = 0;
	homo3[2] = 1;
	homo[2] = homo3;
	return (homo);
}

double** rotation(char* nb, int sym)
{
	double i;
	if (sym == 0) {
		printf("Rotation at a %s degree angle\n", nb);
		i = atof(nb);
	} else
		i = sym * atof(nb);
	double **homo = malloc(sizeof(double**) * 3);
	double *homo1 = malloc(sizeof(double*) * 3);
	homo1[0] = cos(i * (M_PI / 180.0));
	if (homo1[0] < 0 && homo1[0] > -0.000001)
		homo1[0] = 0;
	homo1[1] = -sin(i * (M_PI / 180.0));
	if (homo1[1] < 0 && homo1[1] > -0.000001)
		homo1[1] = 0;
	homo1[2] = 0;
	homo[0] = homo1;
	double *homo2 = malloc(sizeof(double*) * 3);
	homo2[0] = sin(i * (M_PI / 180.0));
	if (homo2[0] < 0 && homo2[0] > -0.000001)
		homo2[0] = 0;
	homo2[1] = cos(i * (M_PI / 180.0));
	if (homo2[1] < 0 && homo2[1] > -0.000001)
		homo2[1] = 0;
	homo2[2] = 0;
	homo[1] = homo2;
	double *homo3 = malloc(sizeof(double*) * 3);
	homo3[0] = 0;
	homo3[1] = 0;
	homo3[2] = 1;
	homo[2] = homo3;
	return (homo);
}

double** symmetry(char* nb)
{
	printf("Symmetry about an axis inclined with an angle of %s degrees\n", nb);
	double** matrice1 = rotation(nb, -1);
	double** matrice2 = homothety("1", "-1", 1);
	matrice1 = multiplication(matrice1, matrice2);
	matrice2 = rotation(nb, 1);
	matrice1 = multiplication(matrice1, matrice2);
	return (matrice1);
}
