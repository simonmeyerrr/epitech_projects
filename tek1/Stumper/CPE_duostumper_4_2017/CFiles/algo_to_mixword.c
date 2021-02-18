/*
** EPITECH PROJECT, 2017
** mixword
** File description:
** init_mixword.c
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"

static void fill_tab(my_mixword_t *mixword)
{
	srand(time(NULL) * getpid());
	for (int i = 0 ; i < mixword->size ; i++) {
		for (int j = 0 ; j < mixword->size ; j++)
			mixword->result[i][j] = (mixword->result[i][j] == ' ') ?
			((rand() % 26) + 'a') : (mixword->result[i][j]);
	}
}

static void add_last_word(my_mixword_t *mixword, char *str)
{
	for (int i = 0 ; str && str[i] ; i++)
		mixword->result[i][mixword->size - 1] = str[i];
}

static void add_on_last_row(my_mixword_t *mixword, my_word_t *tmp)
{
	int len = 0;

	for (int i = 0 ; i < mixword->size &&
	mixword->result[i][mixword->size - 1] == ' ' ; i++)
		len++;
	while (tmp) {
		if (my_strlen(tmp->word) <= len) {
			add_last_word(mixword, tmp->word);
			mixword->used_word += 1;
			return;
		}
		tmp = tmp->next;
	}
}

static void add_word_to_tab(char *word, my_mixword_t *mixword, int i)
{
	for (int j = 0 ; j < my_strlen(word); j++)
		mixword->result[i][j] = word[j];
}

void algo_to_mixword(my_mixword_t *mixword)
{
	my_word_t *tmp = mixword->first_word;

	for (int i = 0 ; i < mixword->size && tmp ; tmp = tmp->next) {
		if (my_strlen(tmp->word) <= mixword->size) {
			add_word_to_tab(tmp->word, mixword, i);
			mixword->used_word += 1;
			i++;
		}
	}
	add_on_last_row(mixword, tmp);
	fill_tab(mixword);
}
