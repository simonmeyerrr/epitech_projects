/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** init_mixword.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

void display_help(void)
{
	my_putstr("USAGE:\n\t./mixword [options]\n\nOPTIONS:\n\t-h --help\t\t"
	"display this help.\n\t-f --file [FILE]\tthe file where words are "
	"taken from.\n\t-s --size SIZE:\t\tdefines the size of the "
	"grid. The value is 8 by default.\n");
	exit(MY_SUCCESS);
}

void display_mixword(my_mixword_t *mixword)
{
	if (mixword->used_word <= 0)
		my_exit("No word could be placed.\n");
	my_put_nb(mixword->used_word);
	write(1, "/", 1);
	my_put_nb(mixword->total_word);
	my_putstr(" words inserted in the grid.\n");
	for (int i = 0 ; i < mixword->size + 2 ; i++)
		write(1, "+", 1);
	write(1, "\n", 1);
	for (int tablen = 0 ; mixword->result[tablen] != NULL ; tablen++) {
		write(1, "|", 1);
		my_putstr(mixword->result[tablen]);
		write(1, "|\n", 2);
	}
	for (int j = 0 ; j < mixword->size + 2 ; j++)
		write(1, "+", 1);
	write(1, "\n", 1);
}
