/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaDoctor.cpp
*/

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include "KoalaDoctor.hpp"
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
    : _name(name), _working(false)
{
    this->say("I'm Dr." + name + "! How do you kreog?");
}

void KoalaDoctor::say(std::string message)
{
    std::cout << "Dr." << this->_name << ": " << message << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string patientName = patient->getName();
    std::string fileName(patientName + ".report");

    this->say("So what's goerking you Mr." + patientName + "?");
    patient->poke();

    std::string drugs[5] = {"mars", "Buronzand", "Viagra", "Extasy",
        "Eucalyptus leaf"};
    std::ofstream inputFile(fileName);
    std::string drug = drugs[random() % 5];
    if (inputFile.is_open()) {
        inputFile << drug;
    }
}

void KoalaDoctor::timeCheck()
{
    if (!this->_working) {
        this->say("Time to get to work!");
        this->_working = true;
    } else {
        this->say("Time to go home to my eucalyptus forest!");
        this->_working = false;
    }
}