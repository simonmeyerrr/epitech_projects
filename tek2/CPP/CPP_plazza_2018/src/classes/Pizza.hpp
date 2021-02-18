/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Pizza.hpp
*/

#ifndef CPP_PLAZZA_2018_PIZZA_HPP
# define CPP_PLAZZA_2018_PIZZA_HPP

#include <deque>
#include <string>
#include <vector>

enum PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
    UNDEFINED_TYPE
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
    UNDEFINED_SIZE
};

enum Ingredient {
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOAT_CHEESE,
    UNDEFINED_ING
};

using Ingredients = std::vector<Ingredient>;
using Recipe = std::pair<int, Ingredients>;

class Pizza {
public:
    static PizzaSize strToSize(const std::string &);
    static std::string sizeToStr(PizzaSize);
    static PizzaType strToType(const std::string &);
    static std::string typeToStr(PizzaType);
    static Ingredients getIngredients(PizzaType);
    static int getTime(PizzaType);
    static Recipe getRecipe(PizzaType);
    static std::deque<std::tuple<PizzaType, PizzaSize, int>> parsePizzas(
        const std::string &);
};

#endif /* CPP_PLAZZA_2018_PIZZA_HPP */
