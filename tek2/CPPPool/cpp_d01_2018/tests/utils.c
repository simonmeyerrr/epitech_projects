/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** utils.c
*/

#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}