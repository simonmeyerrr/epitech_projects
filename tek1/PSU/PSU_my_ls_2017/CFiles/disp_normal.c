/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** disp_normal.c
*/

#include "all.h"

static void disp_normal2(char* path, char* file, flags_t* flag)
{
	struct stat buf;

	if (lstat(create_path(path, file), &buf) < 0) {
		write(2, "Can't find a file or a directory\n", 33);
		exit (84);
	}
	if (flag->list == 1)
		disp_info(buf, flag);
	write(1, file, my_strlen(file));
	write(1, "\n", 1);
	if (flag->recursive == 1 && (buf.st_mode & S_IFMT) == S_IFDIR)
		disp_normal(create_path(path, file), flag);
}

void disp_normal(char* path, flags_t* flag)
{
	struct stat buf;
	DIR* fd = opendir(path);
	struct dirent *dir;

	if (lstat(path, &buf) < 0) {
		write(2, "Can't find a file or a directory\n", 33);
		exit (84);
	}
	if ((buf.st_mode & S_IFMT) != S_IFDIR) {
		disp_d(path, flag);
		return;
	}
	while((dir = readdir(fd)) != NULL) {
		if (dir->d_name[0] != '.')
			disp_normal2(path, dir->d_name, flag);
	}
	closedir(fd);
}

static void search_len_normal2(char* path, char* file, flags_t* flag)
{
	struct stat buf;

	if (lstat(create_path(path, file), &buf) < 0)
		exit (84);
	if (my_nbr_len(buf.st_nlink) > flag->len_link)
		flag->len_link = my_nbr_len(buf.st_nlink);
	if (my_strlen(getpwuid(buf.st_uid)->pw_name) > flag->len_user)
		flag->len_user = my_strlen(getpwuid(buf.st_uid)->pw_name);
	if (my_strlen(getgrgid(buf.st_gid)->gr_name) > flag->len_group)
		flag->len_group = my_strlen(getgrgid(buf.st_gid)->gr_name);
	if (my_nbr_len(buf.st_size) > flag->len_size)
		flag->len_size = my_nbr_len(buf.st_size);
	flag->total = flag->total + buf.st_blocks;
	if (flag->recursive == 1 && (buf.st_mode & S_IFMT) == S_IFDIR)
		search_len_normal(create_path(path, file), flag);
}

void search_len_normal(char* path, flags_t* flag)
{
	struct stat buf;
	DIR* fd = opendir(path);
	struct dirent *dir;

	if (lstat(path, &buf) < 0) {
		write(2, "Can't find a file or a directory\n", 33);
		exit (84);
	}
	if ((buf.st_mode & S_IFMT) != S_IFDIR) {
		search_len_d2(flag, path);
		return;
	}
	flag->file = 1;
	while((dir = readdir(fd)) != NULL) {
		if (dir->d_name[0] != '.')
			search_len_normal2(path, dir->d_name, flag);
	}
	closedir(fd);
}

void ls_normal(flags_t* flag, int ac, char** av)
{
	for (int i = 1 ; i < ac ; i++) {
		if (av[i][0] != '-') {
			prepare_normal(av[i], flag);
			disp_normal(av[i], flag);
			flag->elem = 1;
		}
	}
	if (flag->elem == 0) {
		prepare_normal(".", flag);
		disp_normal(".", flag);
	}
}
