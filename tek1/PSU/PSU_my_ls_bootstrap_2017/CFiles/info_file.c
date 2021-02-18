/*
** EPITECH PROJECT, 2017
** info_file
** File description:
** info_file.c
*/

#include "all.h"

void uid_gid(struct stat buf)
{
	my_putstr("\nUID:  ");
	my_put_nbr(buf.st_uid);
	my_putstr("\nGID:  ");
	my_put_nbr(buf.st_gid);
	write(1, "\n", 1);
}

void major_minor(dev_t dev)
{
	unsigned int minor = minor(dev);
	unsigned int major = major(dev);

	if (major != 0 || minor != 0) {
		my_putstr("\nMinor:  ");
		my_put_nbr(minor);
		my_putstr("\nMajor:  ");
		my_put_nbr(major);
	} else {
		my_putstr("\nMinor:  N/A\nMajor:  N/A");
	}
}

void type_file(mode_t mode)
{
	my_putstr("\nType:  ");
	(mode & S_IFMT) == S_IFREG ? (write(1, "-", 1)) : (0);
	(mode & S_IFMT) == S_IFDIR ? (write(1, "d", 1)) : (0);
	(mode & S_IFMT) == S_IFLNK ? (write(1, "l", 1)) : (0);
	(mode & S_IFMT) == S_IFIFO ? (write(1, "p", 1)) : (0);
	(mode & S_IFMT) == S_IFSOCK ? (write(1, "s", 1)) : (0);
	(mode & S_IFMT) == S_IFCHR ? (write(1, "c", 1)) : (0);
	(mode & S_IFMT) == S_IFBLK ? (write(1, "b", 1)) : (0);
}

void info_file(char *file)
{
	struct stat buf;

	if (lstat(file, &buf) < 0) {
		my_putstr("File not found\n");
		exit (84);
	}
	my_putstr("Name:  ");
	my_putstr(my_get_name(file));
	type_file(buf.st_mode);
	my_putstr("\nInode:  ");
	my_put_nbr(buf.st_ino);
	my_putstr("\nHard Link:  ");
	my_put_nbr(buf.st_nlink);
	my_putstr("\nSize:  ");
	my_put_nbr(buf.st_size);
	my_putstr("\nAllocated space:  ");
	my_put_nbr(buf.st_blocks * 512);
	major_minor(buf.st_rdev);
	uid_gid(buf);
}
