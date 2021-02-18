/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** struct.h
*/

typedef struct flags
{
	int list;
	int recursive;
	int d;
	int reverse;
	int t;
	int g;
	int rev_g;

	int elem;
	int file;

	unsigned int total;
	int len_link;
	int len_user;
	int len_group;
	int len_size;
} flags_t;
