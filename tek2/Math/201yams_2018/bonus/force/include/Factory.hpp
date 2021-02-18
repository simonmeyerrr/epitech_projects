/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Factory.hpp
*/
#ifndef INC_201YAMS_2018_FACTORY_HPP
# define INC_201YAMS_2018_FACTORY_HPP

# include <string>
# include "ICombination.hpp"

class Factory {
public:
    static ICombination *getCombination(const std::string &);

private:
    static ICombination *getPair(const std::string &);
    static ICombination *getThree(const std::string &);
    static ICombination *getFour(const std::string &);
    static ICombination *getFull(const std::string &);
    static ICombination *getStraight(const std::string &);
    static ICombination *getYams(const std::string &);
};

#endif /* INC_201YAMS_2018_FACTORY_HPP */
