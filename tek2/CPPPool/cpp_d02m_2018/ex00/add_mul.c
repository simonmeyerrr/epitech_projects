/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** add_mul.c
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int add = *first + *second;
    int mul = *first * *second;

    *first = add;
    *second = mul;
}