/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** constructor.c
*/

#include "string.h"

void string_init(string_t *string, const char *str)
{
    string->str = my_strdup(str);
    string->init = &string_init;
    string->destroy = &string_destroy;
    string->assign_s = &assign_s;
    string->assign_c = &assign_c;
    string->append_s = &append_s;
    string->append_c = &append_c;
    string->at = &at;
    string->clear = &clear;
    string->size = &size;
    string->compare_s = &compare_s;
    string->compare_c = &compare_c;
    string->copy = &copy;
    string->c_str = &c_str;
    string->empty = &empty;
    string->find_s = &find_s;
    string->find_c = &find_c;
}

void string_destroy(string_t *string)
{
    if (!string)
        return;
    my_free(string->str);
    string->str = NULL;
}