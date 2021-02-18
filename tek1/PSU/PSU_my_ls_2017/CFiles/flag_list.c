/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** flag_list.c
*/

#include "all.h"

void prepare_normal(char* path, flags_t* flag)
{
	(flag->elem != 0) ? write(1, "\n", 1) : (0);
	if (flag->list == 1) {
		flag->len_link = 0;
		flag->len_user = 0;
		flag->len_group = 0;
		flag->len_size = 0;
		flag->total = 0;
		flag->file = 0;
		search_len_normal(path, flag);
		if (flag->file == 1) {
			my_putstr("total ");
			my_putnbr(flag->total / 2);
			write(1, "\n", 1);
		}
	}
}

static void disp_time(struct stat buf, flags_t* flag)
{
	char *str = ctime(&(buf.st_mtime));

	for (int i = 0 ; i < flag->len_size - my_nbr_len(buf.st_size) ; i++)
		write(1, " ", 1);
	my_putnbr(buf.st_size);
	write(1, " ", 1);
	for (int i = 4 ; i < 16 ; i++)
		write(1, &str[i], 1);
	write(1, " ", 1);
}

static void disp_type_perm(mode_t mode)
{
	(mode & S_IFMT) == S_IFREG ? (write(1, "-", 1)) : (0);
	(mode & S_IFMT) == S_IFDIR ? (write(1, "d", 1)) : (0);
	(mode & S_IFMT) == S_IFLNK ? (write(1, "l", 1)) : (0);
	(mode & S_IFMT) == S_IFIFO ? (write(1, "p", 1)) : (0);
	(mode & S_IFMT) == S_IFSOCK ? (write(1, "s", 1)) : (0);
	(mode & S_IFMT) == S_IFCHR ? (write(1, "c", 1)) : (0);
	(mode & S_IFMT) == S_IFBLK ? (write(1, "b", 1)) : (0);
	(mode & S_IRUSR) ? write(1, "r", 1) : write(1, "-", 1);
	(mode & S_IWUSR) ? write(1, "w", 1) : write(1, "-", 1);
	(mode & S_IXUSR) ? write(1, "x", 1) : write(1, "-", 1);
	(mode & S_IRGRP) ? write(1, "r", 1) : write(1, "-", 1);
	(mode & S_IWGRP) ? write(1, "w", 1) : write(1, "-", 1);
	(mode & S_IXGRP) ? write(1, "x", 1) : write(1, "-", 1);
	(mode & S_IROTH) ? write(1, "r", 1) : write(1, "-", 1);
	(mode & S_IWOTH) ? write(1, "w", 1) : write(1, "-", 1);
	(mode & S_IXOTH) ? write(1, "x", 1) : write(1, "-", 1);
	write(1, ". ", 2);
}

void disp_info(struct stat buf, flags_t* flag)
{
	char* str = getpwuid(buf.st_uid)->pw_name;

	disp_type_perm(buf.st_mode);
	for (int i = 0 ; i < flag->len_link - my_nbr_len(buf.st_nlink) ; i++)
		write(1, " ", 1);
	my_putnbr(buf.st_nlink);
	write(1, " ", 1);
	if (flag->rev_g == 0) {
		my_putstr(str);
		for (int i = 0 ; i <= flag->len_user - my_strlen(str) ; i++)
			write(1, " ", 1);
	}
	if (flag->g == 0) {
		str = getgrgid(buf.st_gid)->gr_name;
		my_putstr(str);
		for (int i = 0 ; i <= flag->len_group - my_strlen(str) ; i++)
			write(1, " ", 1);
	}
	disp_time(buf, flag);
}
