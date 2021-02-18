/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_strstr.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>

Test(strstr, strstr)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    int (*my_strstr)(char const *, char const *) = dlsym(lib, "strstr");
    char *str1 = NULL;
    char *str2 = NULL;

    cr_assert_eq(NULL, my_strstr(str1, str2));
    dlclose(lib);
}