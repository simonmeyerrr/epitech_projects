/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** test if there are only digits
*/

int my_str_isnum(char const *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}
