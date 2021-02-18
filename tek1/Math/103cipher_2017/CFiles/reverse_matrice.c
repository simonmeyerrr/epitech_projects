/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** reverse_matrice.c
*/

#include "all.h"

static double** resize_matrice(double** matrice, int i, int j, int size)
{
	double** mat = malloc(sizeof(double**) * (size + 1));
	mat[size] = NULL;
	for (int y = 0 ; y < size ; y++) {
		mat[y] = malloc(sizeof(double*) * size);
		for (int x = 0 ; x < size ; x++) {
			if (y < j) {
				if (x < i)
					mat[y][x] = matrice[y][x];
				else
					mat[y][x] = matrice[y][x + 1];
			} else {
				if (x < i)
					mat[y][x] = matrice[y + 1][x];
				else
					mat[y][x] = matrice[y + 1][x + 1];
			}
		}
	}
	return (mat);
}

static double get_determinant(double** mat, int size)
{
	double det = 0;
	int pair = 1;

	if (size == 2)
		return (mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);
	for (int i = 0 ; i < size ; i++) {
		if (pair > 0)
			det = det + mat[0][i] * get_determinant(resize_matrice(mat, i, 0, size - 1), size - 1);
		else
			det = det - mat[0][i] * get_determinant(resize_matrice(mat, i, 0, size - 1), size - 1);
		pair = -pair;
	}
	return (det);
}

double** get_comatrice(double** mat, int size)
{
	double** comat = malloc(sizeof(double**) * (size + 1));
	comat[size] = NULL;
	if (size == 2) {
		comat[0] = malloc(sizeof(double*) * 2);
		comat[0][0] = mat[1][1];
		comat[0][1] = -mat[1][0];
		comat[1] = malloc(sizeof(double*) * 2);
		comat[1][0] = -mat[0][1];
		comat[1][1] = mat[0][0];
		return (comat);
	}
	for (int i = 0 ; i < size ; i++) {
		comat[i] = malloc(sizeof(double*) * size);
		for (int j = 0 ; j < size ; j++) {
			if ((i + j) % 2 == 0)
				comat[i][j] = 1 * get_determinant(resize_matrice(mat, i, j, size - 1), size - 1);
			else
				comat[i][j] = -1 * get_determinant(resize_matrice(mat, i, j, size - 1), size - 1);
		}
	}
	return (comat);
}

double** reverse_matrice(double** key, int size)
{
	double det = get_determinant(key, size);
	if (det == 0) {
		write(2, "Unreversable matrice.\n", 22);
		exit (84);
	}
	double** comatrice = get_comatrice(key, size);
	double** rev_key = malloc(sizeof(double**) * (size + 1));
	rev_key[size] = NULL;
	int i = 0;
	int j = 0;
	int k = 0;
	int alloc = 1;
	while (j != size) {
		if (alloc == 1)
			rev_key[j] = malloc(sizeof(double*) * size);
		if (i < size)
			rev_key[j][k] = comatrice[i][k] / det;
		else
			rev_key[j][k] = 0;
		if (rev_key[j][k] > -0.0001 && rev_key[j][k] < 0.0001)
			rev_key[j][k] = 0;
		k++;
		alloc = 0;
		if (k == size) {
			alloc = 1;
			k = 0;
			i++;
			j++;
		}
	}
	return (rev_key);
}
