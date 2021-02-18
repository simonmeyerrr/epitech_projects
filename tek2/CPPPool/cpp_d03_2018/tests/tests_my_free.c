/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** tests_my_free.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "string.h"

Test(my_free, null)
{
    void *ptr = NULL;

    my_free(ptr);
}

Test(my_free, malloced)
{
    void *ptr = malloc(sizeof(char) * 3);

    my_free(ptr);
}