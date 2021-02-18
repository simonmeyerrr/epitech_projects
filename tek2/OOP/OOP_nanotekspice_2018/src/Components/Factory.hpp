/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Factory.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_COMPONENTCREATOR_HPP_
# define OOP_NANOTEKSPICE_2018_COMPONENTCREATOR_HPP_

# include <memory>
# include <string>
# include "IComponent.hpp"

namespace nts {

    typedef std::unique_ptr <IComponent> Component;

    class Factory {
    public:
        static std::unique_ptr <IComponent> createComponent(const std::string &,
            const std::string &);

    private:
        static Component createInput(const std::string &);
        static Component createTrue(const std::string &);
        static Component createFalse(const std::string &);
        static Component createClock(const std::string &);
        static Component createOutput(const std::string &);
        static Component create4011(const std::string &);
        static Component create4069(const std::string &);
        static Component create4081(const std::string &);
        static Component create4503(const std::string &);
        static Component create4030(const std::string &);
        static Component create4012(const std::string &);
        static Component create4023(const std::string &);
        static Component create4071(const std::string &);
        static Component create4001(const std::string &);
        static Component create4514(const std::string &);
        static Component create4515(const std::string &);
    };

}

#endif /* OOP_NANOTEKSPICE_2018_COMPONENTCREATOR_HPP_ */
