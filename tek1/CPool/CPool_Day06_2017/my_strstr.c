/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** search a string in a string
*/

#include <unistd.h>

int search_first(char const *str, char const *to_find, int first)
{
	for (int i = first ; str[i] != to_find[0] ; i++) {
		first = i + 1;
		if (str[i] == '\0')
			return (-1);
	}
	return (first);
}

int thetest(char const *str, char const *to_find, int first, int i)
{
	if (str[first + i] != to_find[i])
		return (0);
	else
		return (1);
}

char *my_strstr(char const *str, char const *to_find)
{
	int first = -1;
	int test = 0;
	int length = 0;

	while (to_find[length] != '\0')
		length++;
	while (test == 0) {
		first = first + 1;
		first = search_first(str, to_find, first);
		if (first < 0)
			return (NULL);
		test = 1;
		for (int i = 0 ; i < length && test == 1 ; i++)
			test = thetest(str, to_find, first, i);
	}
	for (int i = 0 ; i < first ; i++)
		str++;
	return (str);
}
