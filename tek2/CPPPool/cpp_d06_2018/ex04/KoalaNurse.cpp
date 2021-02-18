/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaNurse.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int id)
    : _id(id), _working(false)
{}

void KoalaNurse::say(std::string message)
{
    std::cout << "Nurse " << this->_id << ": " << message << std::endl;
}

KoalaNurse::~KoalaNurse()
{
    this->say("Finally some rest!");
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string fileName)
{
    std::string patient = fileName;
    patient.erase(patient.size() - 7, 7);

    std::string drug;
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        char c = inputFile.get();
        while (inputFile.good()) {
            drug += c;
            c = inputFile.get();
        }
    } else {
        inputFile.close();
        return ("");
    }

    this->say("Kreog! Mr." + patient + " needs a " + drug + "!");
    return (drug);
}

void KoalaNurse::timeCheck()
{
    if (!this->_working) {
        this->say("Time to get to work!");
        this->_working = true;
    } else {
        this->say("Time to go home to my eucalyptus forest!");
        this->_working = false;
    }
}