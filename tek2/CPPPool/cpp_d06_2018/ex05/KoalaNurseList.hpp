/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaNurseList.hpp
*/

#ifndef CPP_D06_2018_KOALANURSELIST_HPP_
# define CPP_D06_2018_KOALANURSELIST_HPP_

# include <string>
# include "KoalaNurse.hpp"

class KoalaNurseList {
public:
    // Ctor
    KoalaNurseList(KoalaNurse *);

    //Dtor
    ~KoalaNurseList();

    // Member functions
    bool isBegin();
    bool isEnd();

    KoalaNurseList *getPrev();
    KoalaNurseList *getNext();

    KoalaNurseList *getBegin();
    KoalaNurseList *getEnd();

    void append(KoalaNurseList *);
    KoalaNurseList *remove(KoalaNurseList *);

    KoalaNurse *getFromID(int);
    KoalaNurseList *removeFromID(int);

    KoalaNurse *getContent();
    void dump();

private:

    // Properties
    KoalaNurseList *_prev;
    KoalaNurseList *_next;
    KoalaNurse *_content;
};

#endif /* CPP_D06_2018_KOALANURSELIST_HPP_ */
