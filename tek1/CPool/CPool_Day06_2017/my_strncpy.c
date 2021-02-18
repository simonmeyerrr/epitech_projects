/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copy n char of a string
*/

char *my_strncpy(char *dest, char *src, int n)
{
	for (int i = 0 ; i < n ; i++) {
		if (src[i] == '\0') {
			dest[i] = '\0';
			return (dest);
		}
		dest[i] = src[i];
	}
	return (dest);
}
