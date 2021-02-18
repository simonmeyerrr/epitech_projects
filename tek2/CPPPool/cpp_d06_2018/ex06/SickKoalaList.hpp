/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** SickKoalaList.hpp
*/

#ifndef CPP_D06_2018_SICKKOALALIST_HPP_
# define CPP_D06_2018_SICKKOALALIST_HPP_

# include <string>
# include "SickKoala.hpp"

class SickKoalaList {
public:
    // Ctor
    SickKoalaList(SickKoala *);

    //Dtor
    ~SickKoalaList();

    // Member functions
    bool isBegin();
    bool isEnd();

    SickKoalaList *getPrev();
    SickKoalaList *getNext();

    SickKoalaList *getBegin();
    SickKoalaList *getEnd();

    void append(SickKoalaList *);
    SickKoalaList *remove(SickKoalaList *);

    SickKoala *getFromName(std::string);
    SickKoalaList *removeFromName(std::string);

    bool contain(SickKoalaList *);
    SickKoala *getContent();
    void dump();
    bool isSick();

private:

    // Properties
    SickKoalaList *_prev;
    SickKoalaList *_next;
    SickKoala *_content;
};

#endif /* CPP_D06_2018_SICKKOALALIST_HPP_ */
