/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** castmania.c
*/

#include <stdio.h>
#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *instruction = data;
    instruction_type_t type;
    addition_t *add = instruction->operation;
    division_t *div = instruction->operation;
    integer_op_t *res;

    if (instruction_type == ADD_OPERATION) {
        exec_add(add);
        if (instruction->output_type == VERBOSE) {
            printf("%d\n", add->add_op.res);
        }
    } else if (instruction_type == DIV_OPERATION) {
        exec_div(div);
        res = div->div_op;
        type = ((div->div_type == INTEGER) ? (PRINT_INT) : (PRINT_FLOAT));
        if (instruction->output_type == VERBOSE) {
            exec_instruction(type, &(res->res));
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    int *nb_int;
    float *nb_float;

    if (instruction_type == PRINT_INT) {
        nb_int = data;
        printf("%d\n", *nb_int);
    } else if (instruction_type == PRINT_FLOAT) {
        nb_float = data;
        printf("%f\n", *nb_float);
    } else {
        exec_operation(instruction_type, data);
    }
}