/*
** EPITECH PROJECT, 2018
** cpp_d07a_2018
** File description:
** Skat.hpp
*/

#ifndef CPP_D07A_2018_SKAT_HPP_
# define CPP_D07A_2018_SKAT_HPP_

# include <string>

class Skat {
public:
    Skat(const std::string & = "bob", int = 15);
    ~Skat();

    int &stimPaks();
    const std::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status() const;

private:
    const std::string &_name;
    int _stimPaks;
};

#endif /* CPP_D07A_2018_SKAT_HPP_ */
