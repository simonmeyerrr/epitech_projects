/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** encrypt.c
*/

#include "all.h"

int matrice_size_key(char* key)
{
	int i = 1;

	while (i * i < strlen(key))
		i++;
	return (i);
}

static void display_result(double** mat, int size)
{
	int space = 0;

	for (int i = 0 ; mat[i] != NULL ; i++) {
		for (int j = 0 ; j < size ; j++) {
			if (space == 0)
				space = 1;
			else
				printf(" ");
			printf("%.0lf", mat[i][j]);
		}
	}
	printf("\n");
}

void encrypt(char* str, char* key)
{
	int size = matrice_size_key(key);
	double** key_matrice = get_matrice_square(key, size);
	double** message_matrice = get_matrice(str, size);
	printf("Key matrix :\n");
	display_matrice(key_matrice, size);
	double** result_matrice = multiplication(message_matrice, key_matrice, size, size);
	printf("\nEncrypted message :\n");
	display_result(result_matrice, size);
}
