/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
	int destlen;
	int i = 0;

	destlen = my_strlen(dest);
	while (src[i] != '\0') {
		dest[i + destlen] = src[i];
		i++;
	}
	dest[i + destlen] = '\0';
	return (dest);
}
