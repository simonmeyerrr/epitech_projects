/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaNurse.hpp
*/

#ifndef CPP_D06_2018_KOALANURSE_HPP_
# define CPP_D06_2018_KOALANURSE_HPP_

# include <string>
# include "SickKoala.hpp"

class KoalaNurse {
public:
    // Ctor
    KoalaNurse(int);

    //Dtor
    ~KoalaNurse();

    // Member functions
    void giveDrug(std::string, SickKoala *);
    std::string readReport(std::string);
    void timeCheck();
    int getID();

private:
    void say(std::string);

    // Properties
    int _id;
    bool _working;
};

#endif /* CPP_D06_2018_KOALANURSE_HPP_ */
