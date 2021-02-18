/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct hangman
{
	int tries;
	int nb_words;
	char **tab_words;
	int word_selected;
	char *hidden_word;
	char error;
	char *disp;
} hangman_t;

#endif	/* STRUCT_H_ */
