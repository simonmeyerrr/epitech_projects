/*
** EPITECH PROJECT, 2017
** bootstrap
** File description:
** bootstrap printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_putchar(char);
void my_put_nbr(int);
int my_strlen(char *);
void my_putstr(char *);

int sum_stdarg(int i, int nb, ...)
{
        va_list list;
        int result = 0;

        va_start(list, nb);
        if (i == 0) {
                for (int j = 0 ; j < nb ; j++)
                        result = result + va_arg(list, int);
        } else if (i == 1) {
                for (int j = 0 ; j < nb ; j++)
                        result = result + my_strlen(va_arg(list, char *));
        } else
                result = 84;
        va_end(list);
        return (result);
}

int disp_stdarg(char *s, ...)
{
        va_list list;
        char c;
        char *str;
        int nb;

        va_start(list, s);
        for (int i = 0 ; s[i] != '\0'; i++) {
                if (s[i] == 'c') {
                        c = va_arg(list, int);
                        my_putchar(c);
                } else if (s[i] == 'i') {
                        nb = va_arg(list, int);
                        my_put_nbr(nb);
                } else {
                        str = va_arg(list, char *);
                        my_putstr(str);
                }
                write(1, "\n", 1);
        }
        return (0);
}
