/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_strpbrk.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>

Test(strpbrk, strpbrk)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    char *(*my_strpbrk)(const char *, const char *) = dlsym(lib, "strpbrk");
    char *str = "test oui";
    char *accept = "abcde";

    cr_assert_eq(my_strpbrk(NULL, accept), NULL);
    cr_assert_eq(my_strpbrk(str, NULL), NULL);
    str = "abc";
    accept = "";
    cr_assert_eq(my_strpbrk(str, accept), NULL);
    str = "";
    accept = "abc";
    cr_assert_eq(my_strpbrk(str, accept), NULL);
    str = "test";
    accept = "abc";
    cr_assert_eq(my_strpbrk(str, accept), strpbrk(str, accept));
    str = "test";
    accept = "t";
    cr_assert_eq(my_strpbrk(str, accept), strpbrk(str, accept));
    str = "test";
    accept = "se";
    cr_assert_eq(my_strpbrk(str, accept), strpbrk(str, accept));
    str = "test";
    accept = "e";
    cr_assert_eq(my_strpbrk(str, accept), strpbrk(str, accept));
    dlclose(lib);
}