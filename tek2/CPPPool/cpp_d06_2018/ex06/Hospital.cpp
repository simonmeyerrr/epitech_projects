/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** Hospital.cpp
*/

#include <iostream>
#include <string>
#include "SickKoala.hpp"
#include "SickKoalaList.hpp"
#include "KoalaNurse.hpp"
#include "KoalaNurseList.hpp"
#include "KoalaDoctor.hpp"
#include "KoalaDoctorList.hpp"
#include "Hospital.hpp"

Hospital::Hospital()
    : _doctors(NULL), _patients(NULL), _nurses(NULL)
{}

void Hospital::say(std::string message)
{
    std::cout << "[HOSPITAL] " << message << std::endl;
}

Hospital::~Hospital()
{
    while (this->_nurses) {
        this->_nurses->getContent()->timeCheck();
        this->_nurses = this->_nurses->remove(this->_nurses);
    }
    while (this->_doctors) {
        this->_doctors->getContent()->timeCheck();
        this->_doctors = this->_doctors->remove(this->_doctors);
    }
    while (this->_patients)
        this->_patients = this->_patients->remove(this->_patients);
}

void Hospital::addDoctor(KoalaDoctorList *doctor)
{
    if (!doctor || !doctor->getContent())
        return;
    if (!this->_doctors)
        this->_doctors = doctor;
    else if (this->_doctors->contain(doctor))
        return;
    else
        this->_doctors->append(doctor);
    this->say("Doctor " + doctor->getContent()->getName() + " just arrived!");
    doctor->getContent()->timeCheck();
}

void Hospital::addSick(SickKoalaList *patient)
{
    if (!patient || !patient->getContent())
        return;
    if (!this->_patients)
        this->_patients = patient;
    else if (this->_patients->contain(patient))
        return;
    else
        this->_patients->append(patient);
    this->say("Patient " + patient->getContent()->getName() + " just arrived!");
}

void Hospital::addNurse(KoalaNurseList *nurse)
{
    if (!nurse || !nurse->getContent())
        return;
    if (!this->_nurses)
        this->_nurses = nurse;
    else if (this->_nurses->contain(nurse))
        return;
    else
        this->_nurses->append(nurse);
    this->say("Nurse " +
        std::to_string(nurse->getContent()->getID()) + " just arrived!");
    nurse->getContent()->timeCheck();
}

void Hospital::dump()
{
    this->say("Work starting with:");
    std::cout << "Doctors: ";
    this->_doctors->dump();
    std::cout << "Nurses: ";
    this->_nurses->dump();
    std::cout << "Patients: ";
    this->_patients->dump();
    std::cout << std::endl;
}

void Hospital::manageSick()
{
    this->_doctors->getContent()->diagnose(this->_patients->getContent());
    this->_nurses->getContent()->giveDrug(this->_nurses->getContent()
    ->readReport(this->_patients->getContent()->getName() + ".report"),
    this->_patients->getContent());
}

void Hospital::run()
{
    this->dump();
    while (this->_patients->isSick()) {
        this->manageSick();
        if (!this->_patients->isEnd())
            this->_patients = this->_patients->getNext();
        else
            this->_patients = this->_patients->getBegin();
        if (!this->_doctors->isEnd())
            this->_doctors = this->_doctors->getNext();
        else
            this->_doctors = this->_doctors->getBegin();
        if (!this->_nurses->isEnd())
            this->_nurses = this->_nurses->getNext();
        else
            this->_nurses = this->_nurses->getBegin();
    }
}