/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** finalstumper
*/

#include <unistd.h>
#include "my.h"
#define BUFF_SIZE (4096)

void disp345(int x, int y)
{
	displayrush(3, x, y);
	write(1, " || ", 4);
	displayrush(4, x, y);
	write(1, " || ", 4);
	displayrush(5, x, y);
}

void dif345(char *str, int x, int y)
{
	if (str[x - 1] == 'A') {
		displayrush(3, x, y);
		return;
	}
	if (str[((x + 1) * y) - 2] == 'C') {
		displayrush(4, x, y);
		return;
	}
	if (str[((x + 1) * y) - 2] == 'A') {
		displayrush(5, x, y);
		return;
	}
	write(1, "none", 4);
}

void determinerush(char *str, int x, int y)
{
	switch(str[0]) {
	case 'o':
		displayrush(1, x, y);
		break;
	case '/':
		displayrush(2, x, y);
		break;
	case '*':
		displayrush(2, x, y);
		break;
	case 'B':
		disp345(x, y);
		break;
	case 'A':
		dif345(str, x, y);
		break;
	default:
		write(1, "none", 4);
	}
}

void rush3(char *str)
{
	int x = 0;
	int y = 0;

	while (str[x] != '\n')
		x++;
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] == '\n')
			y++;
	}
	determinerush(str, x, y);
	write(1, "\n", 1);
}

int main(void)
{
	char buff[BUFF_SIZE + 1];
	int offset;
	int len;

	offset = 0;
	while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0)
		offset = offset + len;
	buff[offset] = '\0';
	if (len < 0)
		return (84);
	rush3(buff);
	return (0);
}
