/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** display_hang.c
*/

#include "macro.h"
#include "struct.h"
#include "proto.h"
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <time.h>

void display_hang6(int tries, sfVertexArray *array)
{
	if (tries < 10) {
		sfVertexArray_append(array, create_vertex(
		create_vector(600, 600), sfBlack, create_vector(600, 600)));
		sfVertexArray_append(array, create_vertex(
		create_vector(650, 600), sfBlack, create_vector(650, 600)));
		sfVertexArray_append(array, create_vertex(
		create_vector(650, 0), sfBlack, create_vector(650, 0)));
		sfVertexArray_append(array, create_vertex(
		create_vector(600, 0), sfBlack, create_vector(600, 0)));
	}
	if (tries < 1) {
		sfVertexArray_append(array, create_vertex(
		create_vector(937, 367), sfBlue, create_vector(937, 367)));
		sfVertexArray_append(array, create_vertex(
		create_vector(991, 498), sfBlue, create_vector(991, 498)));
		sfVertexArray_append(array, create_vertex(
		create_vector(959, 498), sfBlue, create_vector(959, 498)));
		sfVertexArray_append(array, create_vertex(
		create_vector(909, 371), sfBlue, create_vector(909, 371)));
	}
}

void display_hang5(int tries, sfVertexArray *array)
{
	if (tries < 3) {
		sfVertexArray_append(array, create_vertex(
		create_vector(953, 236), sfGreen, create_vector(953, 236)));
		sfVertexArray_append(array, create_vertex(
		create_vector(1043, 257), sfGreen, create_vector(1043, 257)));
		sfVertexArray_append(array, create_vertex(
		create_vector(1038, 279), sfGreen, create_vector(1083, 279)));
		sfVertexArray_append(array, create_vertex(
		create_vector(945, 259), sfGreen, create_vector(945, 259)));
	}
	if (tries < 2) {
		sfVertexArray_append(array, create_vertex(
		create_vector(900, 359), sfBlue, create_vector(900, 359)));
		sfVertexArray_append(array, create_vertex(
		create_vector(928, 376), sfBlue, create_vector(928, 376)));
		sfVertexArray_append(array, create_vertex(
		create_vector(880, 494), sfBlue, create_vector(880, 494)));
		sfVertexArray_append(array, create_vertex(
		create_vector(849, 480), sfBlue, create_vector(849, 480)));
	}
}

void display_hang4(int tries, sfVertexArray *array)
{
	if (tries < 5) {
		sfVertexArray_append(array, create_vertex(
		create_vector(914, 217), sfGreen, create_vector(914, 217)));
		sfVertexArray_append(array, create_vertex(
		create_vector(958, 224), sfGreen, create_vector(958, 224)));
		sfVertexArray_append(array, create_vertex(
		create_vector(938, 381), sfGreen, create_vector(938, 381)));
		sfVertexArray_append(array, create_vertex(
		create_vector(894, 374), sfGreen, create_vector(894, 374)));
	}
	if (tries < 4) {
		sfVertexArray_append(array, create_vertex(
		create_vector(920, 225), sfGreen, create_vector(920, 225)));
		sfVertexArray_append(array, create_vertex(
		create_vector(914, 256), sfGreen, create_vector(914, 256)));
		sfVertexArray_append(array, create_vertex(
		create_vector(843, 270), sfGreen, create_vector(843, 270)));
		sfVertexArray_append(array, create_vertex(
		create_vector(842, 240), sfGreen, create_vector(842, 240)));
	}
}

void display_hang3(int tries, sfVertexArray *array)
{
	if (tries < 7) {
		sfVertexArray_append(array, create_vertex(
		create_vector(900, 0), sfBlack, create_vector(900, 0)));
		sfVertexArray_append(array, create_vertex(
		create_vector(930, 0), sfBlack, create_vector(930, 0)));
		sfVertexArray_append(array, create_vertex(
		create_vector(950, 200), sfBlack, create_vector(950, 200)));
		sfVertexArray_append(array, create_vertex(
		create_vector(920, 200), sfBlack, create_vector(920, 200)));
	}
	if (tries < 6) {
		sfVertexArray_append(array, create_vertex(
		create_vector(910, 150), sfRed, create_vector(910, 150)));
		sfVertexArray_append(array, create_vertex(
		create_vector(980, 160), sfRed, create_vector(980, 160)));
		sfVertexArray_append(array, create_vertex(
		create_vector(970, 230), sfRed, create_vector(970, 230)));
		sfVertexArray_append(array, create_vertex(
		create_vector(900, 220), sfRed, create_vector(900, 220)));
	}
}

void display_hang2(int tries, sfVertexArray *array)
{
	if (tries < 9) {
		sfVertexArray_append(array, create_vertex(
		create_vector(600, 0), sfBlack, create_vector(600, 0)));
		sfVertexArray_append(array, create_vertex(
		create_vector(1050, 0), sfBlack, create_vector(1050, 0)));
		sfVertexArray_append(array, create_vertex(
		create_vector(1050, 50), sfBlack, create_vector(1050, 50)));
		sfVertexArray_append(array, create_vertex(
		create_vector(600, 50), sfBlack, create_vector(600, 50)));
	}
	if (tries < 8) {
		sfVertexArray_append(array, create_vertex(
		create_vector(600, 200), sfBlack, create_vector(600, 200)));
		sfVertexArray_append(array, create_vertex(
		create_vector(800, 0), sfBlack, create_vector(800, 0)));
		sfVertexArray_append(array, create_vertex(
		create_vector(800, 50), sfBlack, create_vector(800, 50)));
		sfVertexArray_append(array, create_vertex(
		create_vector(600, 250), sfBlack, create_vector(600, 250)));
	}
}
