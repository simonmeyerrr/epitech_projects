/*
** EPITECH PROJECT, 2017
** hidenp
** File description:
** main.c
*/

#include <unistd.h>

static char *my_search_hiden_str(char *str1, char *str2)
{
	int i = 0;
	int j = 0;

	while (str1[i] != '\0') {
		if (str2[j] == '\0')
			return ("0\n");
		if (str2[j] == str1[i])
			i++;
		j++;
	}
	return ("1\n");
}

int main(int ac, char **av)
{
	char *ret;

	if (ac != 3) {
		write(2, "Usage:\t./hidenp needle haystack\n", 32);
		return (84);
	}
	ret = my_search_hiden_str(av[1], av[2]);
	write(1, ret, 2);
	return (0);
}
