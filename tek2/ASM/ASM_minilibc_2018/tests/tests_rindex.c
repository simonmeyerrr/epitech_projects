/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_rindex.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>

Test(rindex, rindex)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    char *(*my_rindex)(const char *, int) = dlsym(lib, "rindex");
    char *str = strdup("test oui");

    cr_assert_eq(my_rindex(NULL, 'e'), NULL);
    cr_assert_eq(my_rindex(str, 's'), rindex(str, 's'));
    cr_assert_eq(my_rindex(str, 't'), rindex(str, 't'));
    cr_assert_eq(my_rindex(str, 'a'), rindex(str, 'a'));
    cr_assert_eq(my_rindex(str, '\0'), rindex(str, '\0'));
    free(str);
    dlclose(lib);
}