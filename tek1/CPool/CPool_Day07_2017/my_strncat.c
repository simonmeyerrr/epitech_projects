/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** concatenates n part of a string
*/

char *my_strncat(char *dest, char const *src, int nb)
{
	int destlen;
	int i = 0;

	destlen = my_strlen(dest);
	while (i < nb && src[i] != '\0') {
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}
