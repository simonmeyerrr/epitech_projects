/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** tests_redirect_output.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}