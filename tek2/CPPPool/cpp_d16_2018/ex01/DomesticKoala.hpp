/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** DomesticKoala.hpp
*/

#ifndef CPP_D16_2018_DOMESTICKOALA_HPP_
# define CPP_D16_2018_DOMESTICKOALA_HPP_

# include <iostream>
# include <string>
# include <vector>
# include "KoalaAction.hpp"

using methodPointer_t = void (KoalaAction::*)(const std::string &);

class DomesticKoala {
public:
    ~DomesticKoala();
    DomesticKoala(KoalaAction &);
    DomesticKoala(const DomesticKoala &);
    DomesticKoala &operator=(const DomesticKoala &);

    const std::vector <methodPointer_t> *getActions() const;
    void learnAction(unsigned char command, methodPointer_t action);
    void unlearnAction(unsigned char command);
    void doAction(unsigned char command, const std::string &param);
    void setKoalaAction(KoalaAction &);

private:
    KoalaAction &_action;
    std::vector<methodPointer_t> _methods;
    std::vector<unsigned char> _commands;
};

#endif /* CPP_D16_2018_DOMESTICKOALA_HPP_ */
