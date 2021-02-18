/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** Hospital.hpp
*/

#ifndef CPP_D06_2018_HOSPITAL_HPP_
# define CPP_D06_2018_HOSPITAL_HPP_

# include <string>
# include "SickKoala.hpp"
# include "SickKoalaList.hpp"
# include "KoalaNurse.hpp"
# include "KoalaNurseList.hpp"
# include "KoalaDoctor.hpp"
# include "KoalaDoctorList.hpp"

class Hospital {
public:
    // Ctor
    Hospital();

    //Dtor
    ~Hospital();

    // Member functions
    void addDoctor(KoalaDoctorList *);
    void addSick(SickKoalaList *);
    void addNurse(KoalaNurseList *);
    void run();

private:
    void say(std::string);
    void manageSick();
    void dump();

    // Properties
    KoalaDoctorList *_doctors;
    SickKoalaList *_patients;
    KoalaNurseList *_nurses;
};

#endif /* CPP_D06_2018_HOSPITAL_HPP_ */
