/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_strncmp.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

Test(strncmp, strncmp)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    int (*my_strncmp)(char const *, char const *, int) = dlsym(lib, "strncmp");
    char *str1 = NULL;
    char *str2 = NULL;

    cr_assert_eq(0, my_strncmp(str1, str2, 3));
    str1 = NULL;
    str2 = "test";
    cr_assert_eq(0, my_strncmp(str1, str2, 3));
    str1 = "test";
    str2 = NULL;
    cr_assert_eq(0, my_strncmp(str1, str2, 3));
    str1 = "test";
    str2 = "test";
    cr_assert_eq(strncmp(str1, str2, 0), my_strncmp(str1, str2, 0));
    str1 = "";
    str2 = "";
    cr_assert_eq(strncmp(str1, str2, 3), my_strncmp(str1, str2, 3));
    str1 = "test";
    str2 = "test";
    cr_assert_eq(strncmp(str1, str2, 6), my_strncmp(str1, str2, 6));
    str1 = "test";
    str2 = "tess";
    cr_assert_eq(strncmp(str1, str2, 4), my_strncmp(str1, str2, 4));
    str1 = "test";
    str2 = "tess";
    cr_assert_eq(strncmp(str1, str2, 5), my_strncmp(str1, str2, 5));
    str1 = "test";
    str2 = "tess";
    cr_assert_eq(strncmp(str1, str2, 3), my_strncmp(str1, str2, 3));
    dlclose(lib);
}