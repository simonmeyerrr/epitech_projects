/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** copy string with allocated memory
*/

char *my_strdup(char const *src)
{
	char *dest;
	int i = 0;
	int lensrc = my_strlen(src);

	dest = malloc(sizeof(char) * (lensrc + 1));
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i + 1] = '\0';
	return (dest);
}
