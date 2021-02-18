/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** copy string
*/

char *my_strcpy(char *dest, char *src)
{
	int last;

	for (int i = 0 ; src[i] != '\0' ; i++) {
		dest[i] = src[i];
		last = i;
	}
	dest[last + 1] = '\0';
	return (dest);
}
