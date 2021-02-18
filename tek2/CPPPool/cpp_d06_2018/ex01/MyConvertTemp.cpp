/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** MyConvertTemp.cpp
*/

#include <iomanip>
#include <iostream>
#include <string>

int main(void)
{
    float temp;
    std::string type;

    while (std::cin >> temp && std::cin >> type) {
        if (type == "Celsius") {
            temp = temp * 9.0 / 5.0 + 32.0;
            std::cout << std::setw(16) << std::fixed << std::setprecision(3)
                << temp << std::setw(16) << "Fahrenheit" << std::endl;
        } else if (type == "Fahrenheit") {
            temp = 5.0 / 9.0 * (temp - 32.0);
            std::cout << std::setw(16) << std::fixed << std::setprecision(3)
                << temp << std::setw(16) << "Celsius" << std::endl;
        } else
            return (84);
    }
    return (0);
}
