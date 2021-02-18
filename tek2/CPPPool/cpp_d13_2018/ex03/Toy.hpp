/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Toy.hpp
*/

#ifndef CPP_D13_2018_TOY_HPP_
# define CPP_D13_2018_TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    Toy();
    Toy(ToyType, const std::string &, const std::string &);
    Toy(const Toy &other);
    ~Toy();

    ToyType getType() const;

    std::string getName() const;
    void setName(const std::string &name);

    bool setAscii(const std::string &file);
    std::string getAscii() const;

    virtual void speak(const std::string &) const;
    Toy &operator=(const Toy &other);

protected:
    ToyType _type;
    std::string _name;
    Picture _picture;
};

#endif /* CPP_D13_2018_TOY_HPP_ */
