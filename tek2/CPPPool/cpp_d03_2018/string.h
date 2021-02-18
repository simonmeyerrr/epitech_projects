/*
** EPITECH PROJECT, 2018
** cpp_d03_2018
** File description:
** string.h
*/

#ifndef CPP_D03_2018_STRING_H
#define CPP_D03_2018_STRING_H

#include <stddef.h>

typedef struct string_s string_t;

struct string_s {
    char *str;

    // Member functions
    void (*init)(string_t *, const char *);
    void (*destroy)(string_t *);
    void (*assign_s)(string_t *, const string_t *);
    void (*assign_c)(string_t *, const char *);
    void (*append_s)(string_t *, const string_t *);
    void (*append_c)(string_t *, const char *);
    char (*at)(const string_t *, size_t);
    void (*clear)(string_t *);
    int (*size)(const string_t *);
    int (*compare_s)(const string_t *, const string_t *);
    int (*compare_c)(const string_t *, const char *);
    size_t (*copy)(const string_t *, char *, size_t, size_t);
    const char *(*c_str)(const string_t *);
    int (*empty)(const string_t *);
    int (*find_s)(const string_t *, const string_t *, size_t);
    int (*find_c)(const string_t *, const char *, size_t);
};

// constructor.c
void string_init(string_t *, const char *);
void string_destroy(string_t *);

// assign.c
void assign_s(string_t *, const string_t *);
void assign_c(string_t *, const char *);

// append.c
void append_s(string_t *, const string_t *);
void append_c(string_t *, const char *);

// at.c
char at(const string_t *, size_t);

// clear.c
void clear(string_t *);

// size.c
int size(const string_t *);

// compare.c
int compare_s(const string_t *, const string_t *);
int compare_c(const string_t *, const char *);

// copy.c
size_t copy(const string_t *, char *, size_t, size_t);

// c_str.c
const char *c_str(const string_t *);

// empty.c
int empty(const string_t *);

// find.c
int find_s(const string_t *, const string_t *, size_t);
int find_c(const string_t *, const char *, size_t);

// utils.c
void my_free(void *ptr);
int my_strlen(char const *str);
char *my_strdup(char const *str);
char *my_append(char const *str1, char const *str2);

#endif //CPP_D03_2018_STRING_H
