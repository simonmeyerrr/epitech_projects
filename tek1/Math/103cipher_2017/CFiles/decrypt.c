/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** encrypt.c
*/

#include "all.h"

static int special_get_nbr(char* str, int* i)
{
	int nbr = 0;

	while(str[*i] == ' ' && str[*i] != '\0')
		*i = *i + 1;
	while(str[*i] >= '0' && str[*i] <= '9') {
		nbr = nbr * 10 + str[*i] - '0';
		*i = *i + 1;
	}
	return (nbr);
}

static int count_nbr(char* str)
{
	int nbr = 1;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] == ' ')
			nbr++;
	}
	return (nbr);
}

static double** get_encrypted_matrice(char* str, int size)
{
	double** matrice = malloc(sizeof(double**) * ((count_nbr(str) / size) + 2));
	int k = 0;
	int end;

	for (int i = 0 ; k < strlen(str) ; i++) {
		matrice[i] = malloc(sizeof(double*) * size);
		for (int j = 0 ; j < size ; j++) {
			if (k < strlen(str)) {
				matrice[i][j] = special_get_nbr(str, &k);
				k++;
			} else
				matrice[i][j] = 0;
		}
		end = i;
	}
	matrice[end + 1] = NULL;
	return (matrice);
}

static void display_result(double** mat, int size)
{
	char c;

	for (int i = 0 ; mat[i] != NULL ; i++) {
		for (int j = 0 ; j < size ; j++) {
			c = mat[i][j];
			printf("%c", c);
		}
	}
	printf("\n");
}

void display_matrice_double(double** matrice, int width)
{
	char *size = malloc(sizeof(char*) * 20);
	int space_nb;

	for (int i = 0 ; matrice[i] != NULL ; i++) {
		for (int j = 0 ; j < width ; j++) {
			sprintf(size, "%.3lf", matrice[i][j]);
			if (matrice[i][j] == 0.000)
				size[3] = '\0';
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

void decrypt_size_one(char* str, char* key)
{
	if (key[0] == '\0')
		exit(84);
	double char_key = key[0];
	double mat_key = 1.0 / char_key;
	char char_message;
	double** message_matrice = get_encrypted_matrice(str, 1);
	printf("Key matrix :\n%.3lf\n", mat_key);
	printf("\nDecrypted message :\n");
	for (int i = 0 ; message_matrice[i] != NULL; i++) {
		char_message = message_matrice[i][0] / key[0];
		printf("%c", char_message);
	}
	printf("\n");
}

void decrypt(char*str, char* key)
{
	int size = matrice_size_key(key);
	if (size == 1) {
		decrypt_size_one(str, key);
		return;
	}
	double** key_matrice = get_matrice_square(key, size);
	key_matrice = reverse_matrice(key_matrice, size);
	double** message_matrice = get_encrypted_matrice(str, size);
	printf("Key matrix :\n");
	display_matrice_double(key_matrice, size);
	double** result_matrice = multiplication(message_matrice, key_matrice, size, size);
	printf("\nDecrypted message :\n");
	display_result(result_matrice, size);
}
