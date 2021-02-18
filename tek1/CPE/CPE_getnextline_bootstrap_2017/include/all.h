/*
** EPITECH PROJECT, 2017
** getnextline_bootstrap
** File description:
** all.h
*/


#ifndef ALL_H
#define ALL_H

/* includes */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_next_n_bytes(int fd , int n);
void read_and_display_read_line_n(int fd, int n);
char *read_line_and_display_remaining(int fd, int n);

#endif
