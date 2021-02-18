/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** init_hangman.c
*/

#include "macro.h"
#include "struct.h"
#include "proto.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

static void read_file(hangman_t *hangman, char *path)
{
	int fd = open(path, O_RDONLY);
	char *res;
	struct stat info;

	stat(path, &info);
	res = malloc(sizeof(char) * (info.st_size + 1));
	read(fd, res, info.st_size);
	res[info.st_size] = '\0';
	hangman->disp = res;
}

static void open_dictionary(hangman_t *hangman, char *path)
{
	char *buffer;
	int fd = open(path, O_RDONLY);
	struct stat info;

	if (fd < 0) {
		my_put_err("Can't open the file.\n");
		hangman->error = 1;
		return;
	}
	stat(path, &info);
	buffer = malloc(sizeof(char) * (info.st_size + 1));
	if (buffer) {
		read(fd, buffer, info.st_size);
		buffer[info.st_size] = '\0';
		hangman->tab_words = str_to_tab(buffer, "\n");
	}
	my_free(buffer);
	hangman->nb_words = my_tab_len(hangman->tab_words);
	close(fd);
}

static void manage_arg(hangman_t *hangman, int ac, char **av)
{
	if (ac != 2 && ac != 3) {
		my_put_err("Invalid number of arguments.\n");
		hangman->error = 1;
		return;
	}
	if (ac == 3) {
		if (is_nb_valid(av[2]) == 1)
			hangman->tries = my_get_nbr(av[2]);
		else {
			my_put_err("Invalid number of tries.\n");
			hangman->error = 1;
			return;
		}
	}
	open_dictionary(hangman, av[1]);
}

static void check_error_init(hangman_t *hangman)
{
	if (hangman->error != 0)
		return;
	if (hangman->nb_words <= 0) {
		my_put_err("There are not enough words.\n");
		hangman->error = 1;
		return;
	}
	if (hangman->tries <= 0) {
		my_put_err("Positive number of tries expected.\n");
		hangman->error = 1;
		return;
	}
	for (int i = 0 ; hangman->tab_words && hangman->tab_words[i] ; i++) {
		if (is_line_valid(hangman->tab_words[i]) != 1) {
			my_put_err("Invalid line in dictionary\n");
			hangman->error = 1;
			return;
		}
	}
}

hangman_t *init_hangman(int ac, char **av)
{
	hangman_t *hangman = malloc(sizeof(hangman_t));

	if (!hangman) {
		my_put_err("Error while using malloc.\n");
		return (NULL);
	}
	srand(time(NULL) * getpid());
	hangman->tries = 10;
	hangman->nb_words = 0;
	hangman->tab_words = NULL;
	hangman->hidden_word = NULL;
	hangman->error = 0;
	manage_arg(hangman, ac, av);
	check_error_init(hangman);
	if (hangman->error == 0) {
		hangman->word_selected = rand() % hangman->nb_words;
		hangman->hidden_word = get_hidden_word(hangman,
		hangman->tab_words[hangman->word_selected]);
	}
	read_file(hangman, "display_hangman");
	return (hangman);
}
