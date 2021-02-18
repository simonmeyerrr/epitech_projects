/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Picture.hpp
*/

#ifndef CPP_D13_2018_PICTURE_HPP_
# define CPP_D13_2018_PICTURE_HPP_

#include <string>

class Picture {
public:
    Picture(const std::string &file = "");
    Picture(const Picture &other);
    ~Picture();

    bool getPictureFromFile(const std::string &file);

    Picture &operator=(const Picture &other);

    std::string data;
};

#endif /* CPP_D13_2018_PICTURE_HPP_ */
