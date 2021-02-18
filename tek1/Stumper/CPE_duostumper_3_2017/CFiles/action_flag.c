/*
** EPITECH PROJECT, 2017
** minicut
** File description:
** action_flag.c
*/

#include <stdlib.h>
#include "struct.h"
#include "proto.h"

int flag_char_arg(minicut_t *minicut, char *arg)
{
	if (minicut->type != TYPE_UNDEFINED) {
		my_put_err("minicut: only 1 type of list may be specified.\n");
		minicut->error = 1;
		return (0);
	}
	minicut->type = TYPE_CHAR;
	if (manage_numbers_list(minicut, arg) == 0) {
		my_put_err("minicut: invalid list number.\n");
		minicut->error = 1;
		return (0);
	}
	return (0);
}

int flag_char(minicut_t *minicut)
{
	if (minicut->type != TYPE_UNDEFINED) {
		my_put_err("minicut: only 1 type of list may be specified.\n");
		minicut->error = 1;
		return (0);
	}
	minicut->type = TYPE_CHAR;
	return (1);
}

int flag_field_arg(minicut_t *minicut, char *arg)
{
	if (minicut->type != TYPE_UNDEFINED) {
		my_put_err("minicut: only 1 type of list may be specified.\n");
		minicut->error = 1;
		return (0);
	}
	minicut->type = TYPE_FIELD;
	if (manage_numbers_list(minicut, arg) == 0) {
		my_put_err("minicut: invalid list number.\n");
		minicut->error = 1;
		return (0);
	}
	return (0);
}

int flag_field(minicut_t *minicut)
{
	if (minicut->type != TYPE_UNDEFINED) {
		my_put_err("minicut: only 1 type of list may be specified.\n");
		minicut->error = 1;
		return (0);
	}
	minicut->type = TYPE_FIELD;
	return (1);
}

int flag_del_arg(minicut_t *minicut, char *arg)
{
	if (minicut->type != TYPE_UNDEFINED) {
		my_put_err("minicut: only 1 type of list may be specified.\n");
		minicut->error = 1;
		return (0);
	}
	minicut->type = TYPE_CHAR;
	if (my_strlen(arg) == 1)
		minicut->delimiter = arg[0];
	else if (my_strlen(arg) == 3)
		minicut->delimiter = arg[1];
	else {
		my_put_err("minicut: invalid delimiter argument.\n");
		minicut->error = 1;
		return (0);
	}
	return (0);
}
