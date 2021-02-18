/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** disp_d.c
*/

#include "all.h"

void search_len_d2(flags_t* flag, char* path)
{
	struct stat buf;

	if (lstat(path, &buf) < 0) {
		write(2, path, my_strlen(path));
		write(2, ": no such file or directory\n", 28);
		exit (84);
	}
	if (my_nbr_len(buf.st_nlink) > flag->len_link)
		flag->len_link = my_nbr_len(buf.st_nlink);
	if (my_strlen(getpwuid(buf.st_uid)->pw_name) > flag->len_user)
		flag->len_user = my_strlen(getpwuid(buf.st_uid)->pw_name);
	if (my_strlen(getgrgid(buf.st_gid)->gr_name) > flag->len_group)
		flag->len_group = my_strlen(getgrgid(buf.st_gid)->gr_name);
	if (my_nbr_len(buf.st_size) > flag->len_size)
		flag->len_size = my_nbr_len(buf.st_size);
}

static void search_len_d(flags_t* flag, int ac, char** av)
{
	for (int i = 1 ; i < ac ; i++) {
		if (av[i][0] != '-') {
			search_len_d2(flag, av[i]);
			flag->elem = 1;
		}
	}
	if (flag->elem == 0)
		search_len_d2(flag, ".");
	flag->elem = 0;
}

void disp_d(char* path, flags_t* flag)
{
	struct stat buf;

	if (lstat(path, &buf) < 0) {
		write(2, path, my_strlen(path));
		write(2, ": no such file or directory\n", 28);
		exit (84);
	}
	if (flag->list == 1)
		disp_info(buf, flag);
	write(1, path, my_strlen(path));
	write(1, "\n", 1);
}

void ls_d(flags_t* flag, int ac, char **av)
{
	if (flag->list == 1)
		search_len_d(flag, ac, av);
	for (int i = 1 ; i < ac ; i++) {
		if (av[i][0] != '-') {
			disp_d(av[i], flag);
			flag->elem = 1;
		}
	}
	if (flag->elem == 0)
		disp_d(".", flag);
}
