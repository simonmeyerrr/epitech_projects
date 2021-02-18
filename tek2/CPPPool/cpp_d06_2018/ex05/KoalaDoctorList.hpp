/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaDoctorList.hpp
*/

#ifndef CPP_D06_2018_KOALADOCTORLIST_HPP_
# define CPP_D06_2018_KOALADOCTORLIST_HPP_

# include <string>
# include "KoalaDoctor.hpp"

class KoalaDoctorList {
public:
    // Ctor
    KoalaDoctorList(KoalaDoctor *);

    //Dtor
    ~KoalaDoctorList();

    // Member functions
    bool isBegin();
    bool isEnd();

    KoalaDoctorList *getPrev();
    KoalaDoctorList *getNext();

    KoalaDoctorList *getBegin();
    KoalaDoctorList *getEnd();

    bool contain(KoalaDoctorList *);
    void append(KoalaDoctorList *);
    KoalaDoctorList *remove(KoalaDoctorList *);

    KoalaDoctor *getFromName(std::string);
    KoalaDoctorList *removeFromName(std::string);

    KoalaDoctor *getContent();
    void dump();

private:

    // Properties
    KoalaDoctorList *_prev;
    KoalaDoctorList *_next;
    KoalaDoctor *_content;
};

#endif /* CPP_D06_2018_KOALADOCTORLIST_HPP_ */
