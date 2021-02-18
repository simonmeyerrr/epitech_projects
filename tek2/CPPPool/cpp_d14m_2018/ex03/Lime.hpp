/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Lime.hpp
*/

#ifndef CPP_D14M_2018_LIME_HPP_
# define CPP_D14M_2018_LIME_HPP_

# include "Lemon.hpp"

class Lime : public Lemon {
public:
    Lime();
    ~Lime() = default;

    virtual std::string getName() const;
};

#endif /* CPP_D14M_2018_LIME_HPP_ */
