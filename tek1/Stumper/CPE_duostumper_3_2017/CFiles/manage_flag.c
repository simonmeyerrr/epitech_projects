/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** manage_flag.c
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

int get_arg_flag(minicut_t *minicut, char *arg)
{
	if (manage_numbers_list(minicut, arg) == 0) {
		my_put_err("minicut: invalid list number.\n");
		minicut->error = 1;
		return (0);
	}
	return (0);
}

static int flag_del(minicut_t *minicut)
{
	if (minicut->type != TYPE_UNDEFINED) {
		my_put_err("minicut: only 1 type of list may be specified.\n");
		minicut->error = 1;
		return (0);
	}
	minicut->type = TYPE_CHAR;
	return (1);
}

static int manage_long_flag(minicut_t *minicut, char *arg)
{
	int ret = -1;

	if (my_strncmp(arg, "--characters", 11) == 0 && arg[12] == '=')
		ret = flag_char_arg(minicut, arg + 13);
	else if (my_strncmp(arg, "--characters", 11) == 0 && arg[12] == '\0')
		ret = flag_char(minicut);
	if (my_strncmp(arg, "--fields", 7) == 0 && arg[8] == '=')
		ret = flag_field_arg(minicut, arg + 9);
	else if (my_strncmp(arg, "--fields", 7) == 0 && arg[8] == '\0')
		ret = flag_field(minicut);
	if (my_strncmp(arg, "--delimiter", 10) == 0 && arg[11] == '=')
		ret = flag_del_arg(minicut, arg + 12);
	else if (my_strncmp(arg, "--delimiter", 10) == 0 && arg[11] == '\0')
		ret = flag_del(minicut);
	if (ret == -1) {
		my_put_err("minicut: invalid argument.\n");
		minicut->error = 1;
	}
	return (ret);
}

static int manage_short_flag(minicut_t *minicut, char *arg)
{
	int ret = -1;

	if (arg[1] == 'c' && arg[2] != '\0')
		ret = flag_char_arg(minicut, arg + 2);
	else if (arg[1] == 'c' && arg[2] == '\0')
		ret = flag_char(minicut);
	if (arg[1] == 'f' && arg[2] != '\0')
		ret = flag_field_arg(minicut, arg + 2);
	else if (arg[1] == 'f' && arg[2] == '\0')
		ret = flag_field(minicut);
	if (arg[1] == 'd' && arg[2] != '\0')
		ret = flag_del_arg(minicut, arg + 2);
	else if (arg[1] == 'd' && arg[2] == '\0')
		ret = flag_del(minicut);
	if (ret == -1) {
		my_put_err("minicut: invalid argument.\n");
		minicut->error = 1;
	}
	return (ret);
}

int manage_flag(minicut_t *minicut, char *arg)
{
	int arg_nb = 1;

	if (arg[0] == '-' && arg[1] == '-')
		arg_nb = manage_long_flag(minicut, arg);
	else if (arg[0] == '-')
		arg_nb = manage_short_flag(minicut, arg);
	return (arg_nb);
}
