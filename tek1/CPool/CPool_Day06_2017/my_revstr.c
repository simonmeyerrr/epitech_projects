/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
	int i = 0;
	int mid = 0;
	int last;
	char c;

	while (str[i] != '\0')
		i++;
	last = i - 1;
	while (mid < last) {
		c = str[mid];
		str[mid] = str[last];
		str[last] = c;
		last = last - 1;
		mid = mid + 1;
	}
	return (str);
}
