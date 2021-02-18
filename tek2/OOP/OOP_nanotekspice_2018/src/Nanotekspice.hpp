/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Nanotekspice.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_NANOTEKSPICE_HPP_
# define OOP_NANOTEKSPICE_2018_NANOTEKSPICE_HPP_

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Components/IComponent.hpp"

namespace nts {

    class Nanotekspice {
    public:
        ~Nanotekspice() = default;
        Nanotekspice(const std::string &, std::vector<std::string>);

        void display();
        void simulate();
        void loop();
        void dump();
        void changeValue(const std::string &);
        void managePrompt(std::string prompt);
        void takeInput();

    private:
        std::map<std::string, std::unique_ptr <IComponent>> _chipset;
    };

}

#endif /* OOP_NANOTEKSPICE_2018_NANOTEKSPICE_HPP_ */
