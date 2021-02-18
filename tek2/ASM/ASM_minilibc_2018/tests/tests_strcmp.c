/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_strcmp.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <dlfcn.h>

Test(strcmp, strcmp)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    int (*my_strcmp)(char const *, char const *) = dlsym(lib, "strcmp");
    char *str1 = NULL;
    char *str2 = NULL;

    cr_assert_eq(0, my_strcmp(str1, str2));
    str1 = NULL;
    str2 = "test";
    cr_assert_eq(0, my_strcmp(str1, str2));
    str1 = "test";
    str2 = NULL;
    cr_assert_eq(0, my_strcmp(str1, str2));
    str1 = "test";
    str2 = "test";
    cr_assert_eq(0, my_strcmp(str1, str2));
    str1 = "";
    str2 = "";
    cr_assert_eq(0, my_strcmp(str1, str2));
    str1 = "boo";
    str2 = "aoo";
    cr_assert_eq(1, my_strcmp(str1, str2));
    str1 = "obo";
    str2 = "oao";
    cr_assert_eq(1, my_strcmp(str1, str2));
    str1 = "ooa";
    str2 = "oob";
    cr_assert_eq(-1, my_strcmp(str1, str2));
    dlclose(lib);
}