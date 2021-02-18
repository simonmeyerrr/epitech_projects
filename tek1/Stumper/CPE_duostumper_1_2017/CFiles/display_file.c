/*
** EPITECH PROJECT, 2017
** head
** File description:
** display_file.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "proto.h"

static void print_names(argument_t *arg, list_file_t *list)
{
	static int i = 0;

	if (arg->option_name == NAME_VERBOSE || (arg->nb_file > 1
	&& arg->option_name == NAME_NORMAL)) {
		if (i != 0)
			write(1, "\n", 1);
		my_putstr("==> ");
		if (list->name[0] != '-')
			my_putstr(list->name);
		else
			my_putstr("standart output");
		my_putstr(" <==\n");
	}
	i++;
}

static void read_bytes(argument_t *arg, list_file_t *list)
{
	int fd = 0;
	char c;

	fd = (list->name[0] != '-') ? (open(list->name, O_RDONLY)) : (0);
	if (fd < 0) {
		my_put_error("head: cannot open '");
		my_put_error(list->name);
		my_put_error("' for reading: No such file or directory\n");
		arg->error = 1;
	}
	print_names(arg, list);
	for (int i = 0 ; i != arg->option_size_int ; i++) {
		read(fd, &c, 1);
		write(1, &c, 1);
	}
	if (fd > 0)
		close(fd);
}

static void read_lines(argument_t *arg, list_file_t *list)
{
	int fd = 0;
	char *str;

	fd = (list->name[0] != '-') ? (open(list->name, O_RDONLY)) : (0);
	if (fd < 0) {
		my_put_error("head: cannot open '");
		my_put_error(list->name);
		my_put_error("' for reading: No such file or directory\n");
		arg->error = 1;
		return;
	}
	print_names(arg, list);
	for (int i = 0 ; i < arg->option_size_int ; i++) {
		str = get_next_line(fd);
		my_putstr(str);
		my_free(str);
	}
	if (fd > 0)
		close(fd);
}

static list_file_t *create_tmp_list(void)
{
	list_file_t *list = malloc(sizeof(*list));

	list->name = "-";
	return (list);
}

void display_file(argument_t *arg)
{
	list_file_t *tmp2;

	if (arg->nb_file == 0) {
		tmp2 = create_tmp_list();
		if (arg->option_size == SIZE_LINE)
			read_lines(arg, tmp2);
		else
			read_bytes(arg, tmp2);
		my_free(tmp2);
	}
	for (list_file_t *tmp = arg->first_file ; tmp ; tmp = tmp->next) {
		if (arg->option_size == SIZE_LINE)
			read_lines(arg, tmp);
		else
			read_bytes(arg, tmp);
	}
}
