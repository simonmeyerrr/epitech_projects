/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** macro.h
*/

#ifndef MACRO_H_
#define MACRO_H_

#define EXIT_SUCCESS	0
#define EXIT_ERROR	84

#define USAGE1	"Usage:\t"
#define USAGE2	" [options]\nOptions:\n --help\t\t\tDisplay thi\
s help\n -L --level={num}\tStart Tetris at level num (def: 1)\n -l --key-left={\
K}\tMove the tetrimino LEFT using the K key (def: left arrow)\n -r --key-right=\
{K}\tMove the tetrimino RIGHT using the K key (def: right arrow)\n -t --key-tur\
n={K}\tTURN the tetrimino clockwise 90d using the K key (def: top arrow)\n -d -\
-key-drop={K}\tDROP the tetrimino using the K key (def: down arrow)\n -q --key-\
quit={K}\tQUIT the game using the K key (def: `q' key)\n -p --key-pause={K}\tPA\
USE/RESTART the game using the K key (def: space bar)\n --map-size={row,col}\tS\
et the numbers of rows and columns of the map (def: 20,10)\n -w --without-next\
\tHide next tetrimino (def: false)\n -D --debug\t\tDebug mode (def: false)\n"

#define TAB3	{&option->left, &option->right, &option->turn,\
		&option->drop, &option->quit, &option->pause}

#endif	/* MACRO_H_ */
