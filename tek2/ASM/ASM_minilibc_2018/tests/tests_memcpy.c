/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** tests_memcpy.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

Test(memcpy, memcpy)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    void *(*my_memcpy)(void *, void *, size_t) = dlsym(lib, "memcpy");
    char *str1 = strdup("abcde");
    char *str2 = strdup("fghij");

    cr_assert_eq(NULL, my_memcpy(NULL, NULL, 5));
    cr_assert_eq(NULL, my_memcpy(NULL, str2, 5));
    cr_assert_eq(str1, my_memcpy(str1, NULL, 5));
    cr_assert_eq(str1, my_memcpy(str1, str2, 0));
    cr_assert_str_eq(str1, "abcde");
    cr_assert_str_eq(str2, "fghij");
    cr_assert_eq(str1, my_memcpy(str1, str2, 2));
    cr_assert_str_eq(str1, "fgcde");
    cr_assert_str_eq(str2, "fghij");
    my_memcpy(str2 + 1, str1 + 2, 3);
    cr_assert_str_eq(str1, "fgcde");
    cr_assert_str_eq(str2, "fcdej");
    cr_assert_eq(str1, my_memcpy(str1, str2, 5));
    cr_assert_str_eq(str1, "fcdej");
    cr_assert_str_eq(str2, "fcdej");
    free(str1);
    free(str2);
    dlclose(lib);
}