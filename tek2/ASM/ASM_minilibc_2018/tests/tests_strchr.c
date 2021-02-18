/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_strchr.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>

Test(strchr, strchr)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    char *(*my_strchr)(const char *, int) = dlsym(lib, "strchr");
    char *str = strdup("test oui");

    cr_assert_eq(my_strchr(NULL, 'e'), NULL);
    cr_assert_eq(my_strchr(str, 's'), strchr(str, 's'));
    cr_assert_eq(my_strchr(str, 't'), strchr(str, 't'));
    cr_assert_eq(my_strchr(str, 'a'), strchr(str, 'a'));
    cr_assert_eq(my_strchr(str, '\0'), strchr(str, '\0'));
    free(str);
    dlclose(lib);
}