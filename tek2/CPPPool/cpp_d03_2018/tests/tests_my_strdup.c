/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** tests_my_strdup.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "string.h"

Test(my_strdup, null)
{
    char *str = my_strdup(NULL);

    cr_assert_null(str);
}

Test(my_strdup, empty)
{
    char *str = my_strdup("");

    cr_assert_str_eq(str, "");
}

Test(my_strdup, one_char)
{
    char *str = my_strdup("a");

    cr_assert_str_eq(str, "a");
}

Test(my_strdup, normal)
{
    char *str1 = my_strdup("I love Epitech");
    char *str2 = my_strdup("Si senir la baela de la bitta");

    cr_assert_str_eq(str1, "I love Epitech");
    cr_assert_str_eq(str2, "Si senir la baela de la bitta");
}