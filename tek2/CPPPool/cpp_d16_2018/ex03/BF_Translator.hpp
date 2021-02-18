/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** BF_Translator.hpp
*/

#ifndef CPP_D16_2018_BF_TRANSLATOR_HPP_
# define CPP_D16_2018_BF_TRANSLATOR_HPP_

# include <iostream>
# include <fstream>
# include <string>

# define ENDL std::endl
# define TAB "    "

class BF_Translator {
public:
    ~BF_Translator() = default;
    BF_Translator() = default;

    static int translate(const std::string &in, const std::string &out);
};

#endif /* CPP_D16_2018_BF_TRANSLATOR_HPP_ */
