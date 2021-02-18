/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** MyCat.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

void myCat(char const *file)
{
    std::string fileName(file);
    std::ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        char c = inputFile.get();
        while (inputFile.good()) {
            std::cout << c;
            c = inputFile.get();
        }
    } else {
        std::cerr << "my_cat: " << fileName << ": No such file or directory"
            << std::endl;
    }
    inputFile.close();
}

int main(int ac, char const **av)
{
    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (84);
    }
    for (int i = 1; i < ac; i++)
        myCat(av[i]);
    return (0);
}
