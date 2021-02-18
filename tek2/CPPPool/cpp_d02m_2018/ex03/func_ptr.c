/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** func_ptr.c
*/

#include <stdio.h>
#include <unistd.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int len = 0;

    for (int i = 0; str && str[i]; i++)
        len++;
    for (int i = len - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] + 'A' - 'a');
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    if (str)
        printf("42\n");
    else
        printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*func[4])(const char *) = {print_normal,
        print_reverse, print_upper, print_42};

    func[action](str);
}