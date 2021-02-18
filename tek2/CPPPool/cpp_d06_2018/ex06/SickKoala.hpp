/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** SickKoala.hpp
*/

#ifndef CPP_D06_2018_SICKKOALA_HPP_
# define CPP_D06_2018_SICKKOALA_HPP_

# include <string>

class SickKoala {
public:
    // Ctor
    SickKoala(std::string);

    //Dtor
    ~SickKoala();

    // Member functions
    void poke();
    bool takeDrug(std::string);
    void overDrive(std::string);
    std::string getName();
    bool isSick();

private:
    void say(std::string);

    // Properties
    std::string _name;
    bool _sick;
};

#endif /* CPP_D06_2018_SICKKOALA_HPP_ */
