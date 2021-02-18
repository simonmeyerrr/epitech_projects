/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** test if there are only letter
*/

int my_str_isalpha(char const *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))
			return (0);
	}
	return (1);
}
