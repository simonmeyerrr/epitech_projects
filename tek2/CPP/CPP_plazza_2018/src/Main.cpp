/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** main.cpp
*/

#include <thread>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <iostream>
#include "classes/Args.hpp"
#include "classes/Stock.hpp"
#include "classes/Reception.hpp"

int main(int ac, const char **av)
{
    (void)ac;
    (void)av;
    Reception rec(10, 10, 1000);

    rec.order("Regina XL x3");
    std::string line;
    std::getline(std::cin, line);
    rec.nothing();
    return (0);
}