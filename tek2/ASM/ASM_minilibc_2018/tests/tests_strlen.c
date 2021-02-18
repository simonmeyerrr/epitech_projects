/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_strlen.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <dlfcn.h>

Test(strlen, strlen)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    size_t (*my_strlen)(char const *) = dlsym(lib, "strlen");
    char *str;

    str = NULL;
    cr_assert_eq(0, my_strlen(str));
    str = "";
    cr_assert_eq(0, my_strlen(str));
    str = "test";
    cr_assert_eq(4, my_strlen(str));
    dlclose(lib);
}