/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** proto.h
*/

int matrice_size_key(char* key);
void decrypt(char*str, char* key);
void encrypt(char* str, char* key);
double** get_matrice(char* str, int size);
double** inverse_matrice(double** mat, int size);
double** get_matrice_square(char* str, int size);
void display_matrice(double** matrice, int width);
double** multiplication(double** mat1, double** mat2, int width1, int width2);
double** reverse_matrice(double** key, int size);
void decrypt_size_one(char* str, char* key);
