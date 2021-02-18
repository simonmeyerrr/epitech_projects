/*
** EPITECH PROJECT, 2022
** OOP_nanotekspice_2018
** File description:
** main.cpp
*/

#include <string>
#include <vector>
#include <iostream>
#include "Errors.hpp"
#include "Nanotekspice.hpp"

static void print_usage(const std::string &cmd)
{
    std::cout << "USAGE:" << std::endl << "\t" << cmd;
    std::cout << " circuit_file.nts [ [input_name=input_value] ... ]";
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    std::vector<std::string> values;

    if (ac < 2) {
        print_usage(std::string(av[0]));
        return (84);
    }
    for (int i = 2; i < ac; i++)
        values.push_back(std::string(av[i]));
    try {
        nts::Nanotekspice nano(std::string(av[1]), values);
        nano.takeInput();
    } catch (const nts::Errors &e) {
        e.dump();
        return (84);
    } catch (...) {
        return (84);
    }
    return (0);
}

