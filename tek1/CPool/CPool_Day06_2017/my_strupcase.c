/*
** EPITECH PROJECT, 2017
** my_strupcase.c
** File description:
** up letter
*/

char *my_strupcase(char *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] > 96 && str[i] < 123)
			str[i] = str[i] - 32;
	}
	return (str);
}
