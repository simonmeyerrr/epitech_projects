/*
** EPITECH PROJECT, 2017
** my_params_to_array.c
** File description:
** create a struct array with args
*/

#include <stdlib.h>
#include "include/my.h"

char *cpymystr(char const *src)
{
	char dest[my_strlen(src) + 1];
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct info_params *my_params_to_array(int ac, char **av)
{
	struct info_params *ptr;

	ptr = malloc(sizeof(struct info_params) * ac);

	for (int i = 0 ; i < ac ; i++) {
		ptr[i].length = my_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = cpymystr(av[i]);
		ptr[i].tab = my_str_to_word_array(av[i]);
	}
	return (ptr);
}
