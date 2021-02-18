/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** matrice.c
*/

#include "all.h"

void display_matrice(double** matrice, int width)
{
	char *size = malloc(sizeof(char*) * 20);
	int space_nb;

	for (int i = 0 ; matrice[i] != NULL ; i++) {
		for (int j = 0 ; j < width ; j++) {
			sprintf(size, "%.0lf", matrice[i][j]);
			printf("%s", size);
			space_nb = 11 - strlen(size);
			for (int k = 0 ; k < space_nb  && j < width - 1; k++) {
				printf(" ");
			}
		}
		printf("\n");
	}
	free(size);
}

double** get_matrice_square(char* str, int size)
{
	double** matrice = malloc(sizeof(double**) * ((strlen(str) / size) + 2));
	int k = 0;
	int end;

	for (int i = 0 ; i < size ; i++) {
		matrice[i] = malloc(sizeof(double*) * size);
		for (int j = 0 ; j < size ; j++) {
			if (k < strlen(str)) {
				matrice[i][j] = str[k];
				k++;
			} else
				matrice[i][j] = 0;
		}
		end = i;
	}
	matrice[end + 1] = NULL;
	return (matrice);
}

double** get_matrice(char* str, int size)
{
	double** matrice = malloc(sizeof(double**) * ((strlen(str) / size) + 2));
	int k = 0;
	int end;

	for (int i = 0 ; k < strlen(str) ; i++) {
		matrice[i] = malloc(sizeof(double*) * size);
		for (int j = 0 ; j < size ; j++) {
			if (k < strlen(str)) {
				matrice[i][j] = str[k];
				k++;
			} else
				matrice[i][j] = 0;
		}
		end = i;
	}
	matrice[end + 1] = NULL;
	return (matrice);
}

static int get_height(double** matrice)
{
	int i = 0;

	while (matrice[i] != NULL)
		i++;
	return (i);
}

double** multiplication(double** mat1, double** mat2, int width1, int width2)
{
	int height1 = get_height(mat1);
	int height2 = get_height(mat2);
	double** matrice = malloc(sizeof(double**) * (height1 + 1));
	double nb;

	if (height2 != width1) {
		write(2, "Invalid matrice multiplication\n", 31);
		exit (EXIT_ERROR);
	}
	for (int i = 0 ; i < height1 ; i++) {
		matrice[i] = malloc(sizeof(double*) * (width1));
		for (int j = 0 ; j < width2 ; j++) {
			nb = 0;
			for (int k = 0 ; k < width1 ; k++) {
				nb += mat1[i][k] * mat2[k][j];
			}
			matrice[i][j] = nb;
		}
	}
	matrice[height1] = NULL;
	return (matrice);
}
