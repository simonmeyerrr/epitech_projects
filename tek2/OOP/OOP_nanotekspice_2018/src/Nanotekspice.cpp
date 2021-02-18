/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Nanotekspice.cpp
*/

#include <iostream>
#include "Nanotekspice.hpp"
#include "Components/Link.hpp"
#include "Parser.hpp"

namespace nts {
    Nanotekspice::Nanotekspice(const std::string &file,
        std::vector<std::string> values)
    {
        _chipset = nts::Parser::getChipset(file, values);
        for (auto it = values.begin(); it != values.end(); it++)
            changeValue(*it);
        auto it = _chipset.begin();
        while (it != _chipset.end()) {
            if ((*(it->second)).getType() == nts::OUTPUT) {
                (*(it->second)).compute(0);
            }
            it++;
        }
        display();
    }

    void Nanotekspice::display()
    {
        auto it = _chipset.begin();

        while (it != _chipset.end()) {
            if ((*(it->second)).getType() == nts::OUTPUT) {
                std::cout << it->first << "="
                    << nts::tristateToString((*(it->second)).compute(1))
                    << std::endl;
            }
            it++;
        }
    }

    void Nanotekspice::simulate()
    {
        auto it = _chipset.begin();
        while (it != _chipset.end()) {
            if ((*(it->second)).getType() == nts::CLOCK)
                (*(it->second)).updateState(nts::UNDEFINED);
            it++;
        }

        it = _chipset.begin();
        while (it != _chipset.end()) {
            if ((*(it->second)).getType() == nts::OUTPUT) {
                (*(it->second)).compute(0);
            }
            it++;
        }
    }

    void Nanotekspice::loop()
    {
        try {
            while (1) {
                simulate();
                display();
            }
        } catch (...) {
        }
    }

    void Nanotekspice::dump()
    {
        auto it = _chipset.begin();

        while (it != _chipset.end()) {
            (*(it->second)).dump();
            it++;
        }
    }

    void Nanotekspice::changeValue(const std::string &line)
    {
        size_t pos = line.find("=");
        if (pos == std::string::npos)
            throw std::exception();

        std::string component = line.substr(0, pos);
        std::string value = line.substr(pos + 1, line.size());

        pos = value.find("=");
        if (pos != std::string::npos)
            throw std::exception();
        _chipset.at(component)->updateState(stringToTristate(value));
    }

    void Nanotekspice::managePrompt(std::string prompt)
    {
        std::string tab[] = {"display", "simulate", "loop", "dump"};
        void (nts::Nanotekspice::*funcs[])() = {&nts::Nanotekspice::display,
            &nts::Nanotekspice::simulate, &nts::Nanotekspice::loop,
            &nts::Nanotekspice::dump};

        for (size_t i = 0; i < 4; i++) {
            if (prompt == tab[i]) {
                (this->*funcs[i])();
                return;
            }
        }
        changeValue(prompt);
    }

    void Nanotekspice::takeInput()
    {
        std::string prompt;
        std::cout << "> ";
        while (std::cin >> prompt && prompt != "exit") {
            if (!prompt.empty())
                managePrompt(prompt);
            std::cout << "> ";
        }
    }
}