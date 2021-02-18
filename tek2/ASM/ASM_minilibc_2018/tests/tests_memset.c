/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2018
** File description:
** memset.c
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <dlfcn.h>

Test(memset, memset)
{
    void *lib = dlopen("../libasm.so", RTLD_LAZY);
    void *(*my_memset)(void *, int, size_t) = dlsym(lib, "memset");
    char *str = malloc(sizeof(char) * 6);

    cr_assert_eq(NULL, my_memset(NULL, 10, 10));
    cr_assert_eq((void *)str, my_memset(str, 10, 0));
    cr_assert_eq(str, my_memset(str, '\0', 6));
    for (int i = 0; i < 6; i++)
        cr_assert_eq(str[i], '\0');
    cr_assert_str_eq("11111", my_memset(str, '1', 5));
    cr_assert_str_eq("22111", my_memset(str, '2', 2));
    free(str);
    dlclose(lib);
}