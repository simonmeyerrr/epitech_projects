/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** white_rabbit.c
*/

#include <stdlib.h>
#include <unistd.h>

int follow_the_white_rabbit(void)
{
    int sum = 0;
    int res = 0;

    while (res != 37 && res != 1 && sum != 421 && sum != 397) {
        res = random() % 37 + 1;
        sum += res;
        if (res == 10 || res == 15 || res == 23)
            write(1, "forward\n", 8);
        if (res == 26 || res % 8 == 0)
            write(1, "backward\n", 9);
        if (res == 13 || (res > 33 && res < 37))
            write(1, "right\n", 6);
        if ((res > 3 && res < 7) || (res > 16 && res < 22) || res == 28)
            write(1, "left\n", 5);
    }
    write(1, "RABBIT!!!\n", 10);
    return (sum);
}