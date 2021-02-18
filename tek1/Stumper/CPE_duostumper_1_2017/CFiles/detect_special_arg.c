/*
** EPITECH PROJECT, 2017
** head
** File description:
** detect_special_arg.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"

int get_value_arg(argument_t *arg, char *str)
{
	if (my_strlen(str) == 0)
		return (1);
	for (int i = 0 ; str && str[i] ; i++)
		if (str[i] < '0' || str[i] > '9') {
			my_put_error("head: invalid number of ");
			my_put_error((arg->option_size == SIZE_LINE) ?
			"lines" : "bytes");
			my_put_error(": \'");
			my_put_error(str);
			my_put_error("\'\n");
			arg->error = 1;
			return (1);
		}
	arg->option_size_int = my_get_nbr(str);
	return (0);
}

int get_simple_arg(argument_t *arg, char c)
{
	switch (c) {
	case 'q':
		arg->option_name = NAME_QUIET;
		break;
	case 'v':
		arg->option_name = NAME_VERBOSE;
		break;
	case 'n':
		arg->option_size = SIZE_LINE;
		return (1);
	case 'c':
		arg->option_size = SIZE_BYTES;
		return (1);
	default:
		arg->error = 1;
		my_put_error("head: invalid option -- \'");
		write(2, &c, 1);
		my_put_error("\'\nTry 'head --help' for more information.\n");
	}
	return (0);
}

int get_long_arg(argument_t *arg, char *str)
{
	if (my_strcmp(str, "--quiet") == 0 || my_strcmp(str, "--silent") == 0) {
		arg->option_name = NAME_QUIET;
		return (0);
	}
	if (my_strcmp(str, "--verbose") == 0) {
		arg->option_name = NAME_VERBOSE;
		return (0);
	}
	if (my_strcmp(str, "--lines") == 0) {
		arg->option_size = SIZE_LINE;
		return (1);
	}
	if (my_strcmp(str, "--bytes") == 0) {
		arg->option_size = SIZE_BYTES;
		return (1);
	}
	arg->error = 1;
	my_put_error("head: unrecognized option \'");
	my_put_error(str);
	my_put_error("\'\nTry 'head --help' for more information.\n");
}

int get_special_arg(argument_t *arg, char *str)
{
	if (my_strlen(str) > 2 && str[0] == '-' && str[1] == '-')
		return (get_long_arg(arg, str));
	for (int i = 1 ; str && str[i] ; i++) {
		if (get_simple_arg(arg, str[i]) == 1)
			return (2);
	}
	return (0);
}

int get_value_arg_spe(argument_t *arg, char *str)
{
	int i = 1;
	int a = my_strlen(str);
	char *new = NULL;

	for (i ; str[i] == 'q' || str[i] == 'v' ; i++);
	i++;
	a -= i;
	new = malloc(sizeof(char) * (a + 1));
	new[a] = '\0';
	for (int j = 0 ; j < a ; j++) {
		new[j] = str[i];
		i++;
	}
	a = get_value_arg(arg, new);
	my_free(new);
	return (a);
}
