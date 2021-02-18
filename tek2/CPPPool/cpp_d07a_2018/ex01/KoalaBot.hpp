/*
** EPITECH PROJECT, 2018
** cpp_d07a_2018
** File description:
** KoalaBot.hpp
*/

#ifndef CPP_D07A_2018_KOALABOT_HPP_
# define CPP_D07A_2018_KOALABOT_HPP_

# include <string>
# include "Parts.hpp"

class KoalaBot {
public:
    // Ctor and Dtor
    KoalaBot(std::string const & = "Bob-01");
    ~KoalaBot();

    // Member functions
    void informations() const;
    void setParts(const Arms &);
    void setParts(const Legs &);
    void setParts(const Head &);
    void swapParts(Arms &);
    void swapParts(Legs &);
    void swapParts(Head &);
    bool status() const;

private:
    // Properties
    std::string _serial;
    Arms _arms;
    Legs _legs;
    Head _head;
};

#endif /* CPP_D07A_2018_KOALABOT_HPP_ */
