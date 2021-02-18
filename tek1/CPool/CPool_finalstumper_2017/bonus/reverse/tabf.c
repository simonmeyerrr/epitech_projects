/*
** EPITECH PROJECT, 2017
** tabf.c
** File description:
** bonus reverse finalstumper
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int linelen(char *str, int *i)
{
	int len = 0;
	int j = *i;

	while (str[j] != '\n') {
		len++;
		j++;
	}
	return (len);
}

char *newline(char *str, int *i)
{
	char *line = malloc(sizeof(char) * (linelen(str, i) + 1));
	int j = 0;

	while (str[*i] != '\n') {
		line[j] = str[*i];
		*i = *i + 1;
		j++;
	}
	line[j] = '\0';
	return (line);
}

int nbsep(char *str)
{
	int sep = 0;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] == '\n')
			sep++;
	}
	return (sep);
}

char **my_str_to_strtab(char *str)
{
	char **tab = malloc(sizeof(char*) * (nbsep(str) + 1));
	int arr = 0;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		tab[arr] = newline(str, &i);
		arr++;
	}
	tab[arr + 1] = NULL;
	return (tab);
}

void disptab(char **tab)
{
	int arr = 0;

	while (tab[arr] != NULL) {
		for (int i = 0 ; tab[arr][i] != '\0' ; i++)
			write(1, &tab[arr][i], 1);
		write(1, "\n", 1);
		arr++;
	}
}
