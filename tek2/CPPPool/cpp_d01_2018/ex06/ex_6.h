/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** ex_6.h
*/

#ifndef CPP_D01_2018_EX_6_H
#define CPP_D01_2018_EX_6_H

#include <stdint.h>

typedef union foo_foo_bar {
    uint16_t foo;
    uint16_t bar;
} foo_foo_bar_t;

typedef struct foo_foo {
    uint16_t foo;
    foo_foo_bar_t bar;
} foo_foo_t;

typedef union foo {
    foo_foo_t foo;
    uint32_t bar;
} foo_t;

#endif //CPP_D01_2018_EX_6_H
