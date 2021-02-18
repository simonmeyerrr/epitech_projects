/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** redirect_all_std.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
