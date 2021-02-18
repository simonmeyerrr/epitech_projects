/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaDoctor.hpp
*/

#ifndef CPP_D06_2018_KOALADOCTOR_HPP_
# define CPP_D06_2018_KOALADOCTOR_HPP_

# include <string>
# include "KoalaNurse.hpp"
# include "SickKoala.hpp"

class KoalaDoctor {
public:
    // Ctor
    KoalaDoctor(std::string);

    //Dtor
    ~KoalaDoctor();

    // Member functions
    void diagnose(SickKoala *);
    void timeCheck();

private:
    void say(std::string);

    // Properties
    std::string _name;
    bool _working;
};

#endif /* CPP_D06_2018_KOALADOCTOR_HPP_ */
