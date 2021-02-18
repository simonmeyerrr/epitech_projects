/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Factory.cpp
*/

#include "../Errors.hpp"
#include "Factory.hpp"
#include "Input.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "Output.hpp"
#include "C4011.hpp"
#include "C4069.hpp"
#include "C4081.hpp"
#include "C4503.hpp"
#include "C4030.hpp"
#include "C4012.hpp"
#include "C4023.hpp"
#include "C4071.hpp"
#include "C4001.hpp"
#include "C4514.hpp"
#include "C4515.hpp"

namespace nts {

    Component Factory::createInput(const std::string &value)
    {
        return (Component(new Input(value)));
    }

    Component Factory::createTrue(const std::string &value)
    {
        return (Component(new True(value)));
    }

    Component Factory::createFalse(const std::string &value)
    {
        return (Component(new False(value)));
    }

    Component Factory::createClock(const std::string &value)
    {
        return (Component(new Clock(value)));
    }

    Component Factory::createOutput(const std::string &value)
    {
        return (Component(new Output(value)));
    }

    Component Factory::create4011(const std::string &value)
    {
        return (Component(new C4011(value)));
    }

    Component Factory::create4069(const std::string &value)
    {
        return (Component(new C4069(value)));
    }

    Component Factory::create4081(const std::string &value)
    {
        return (Component(new C4081(value)));
    }

    Component Factory::create4503(const std::string &value)
    {
        return (Component(new C4503(value)));
    }

    Component Factory::create4030(const std::string &value)
    {
        return (Component(new C4030(value)));
    }

    Component Factory::create4012(const std::string &value)
    {
        return (Component(new C4012(value)));
    }

    Component Factory::create4023(const std::string &value)
    {
        return (Component(new C4023(value)));
    }

    Component Factory::create4071(const std::string &value)
    {
        return (Component(new C4071(value)));
    }

    Component Factory::create4001(const std::string &value)
    {
        return (Component(new C4001(value)));
    }

    Component Factory::create4514(const std::string &value)
    {
        return (Component(new C4514(value)));
    }

    Component Factory::create4515(const std::string &value)
    {
        return (Component(new C4515(value)));
    }

    Component Factory::createComponent(const std::string &type,
        const std::string &value)
    {
        std::string tab[] = {"input", "true", "false", "clock", "output",
            "4081", "4011", "4503", "4069", "4030", "4012", "4023", "4071",
            "4001", "4514", "4515"};
        Component(*funcs[])(const std::string &) =
        {
            &createInput, &createTrue, &createFalse, &createClock,
            &createOutput, &create4081, &create4011, &create4503, &create4069,
            &create4030, &create4012, &create4023, &create4071, &create4001,
            &create4514, &create4515
        };

        for (size_t i = 0; i < 16; i++) {
            if (type == tab[i])
                return funcs[i](value);
        }
        throw nts::FactoryError("Invalid component name", "Factory");
    }
}