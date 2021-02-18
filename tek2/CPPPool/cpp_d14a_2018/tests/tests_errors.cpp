/*
** EPITECH PROJECT, 2018
** cpp_d14a_2018
** File description:
** tests_errors.cpp
*/

#include <criterion/criterion.h>
#include <cassert>
#include <cstring>
#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"
#include "Engine.hpp"
#include "AtmosphereRegulator.hpp"
#include "Oxygenator.hpp"

Test(WaterReclaimer, water_reclaimer)
{
    WaterReclaimer reclaimer;
    bool hasExcept = false;

    try {
    reclaimer.start();
    } catch (MissionCriticalError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "WaterReclaimer");
        cr_assert(std::strcmp(error.what(),
            "Not enough water to achieve the mission.") == 0);
    }
    cr_assert(hasExcept);
    for (size_t i = 0; i < 10; ++i)
        reclaimer.generateWater();
    reclaimer.start();
    hasExcept = false;
    try {
        reclaimer.generateWater();
    } catch (NasaError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "WaterReclaimer");
        cr_assert(std::strcmp(error.what(),
            "Cannot generate water, reclaimer already full.") == 0);
    }
    cr_assert(hasExcept);

    hasExcept = false;
    try {
        reclaimer.generateWater();
    } catch (std::exception const &error) {
        hasExcept = true;
    }
    cr_assert(hasExcept);
    hasExcept = false;
    try {
        reclaimer.generateWater();
    } catch (NasaError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "WaterReclaimer");
    }
    cr_assert(hasExcept);

    reclaimer.useWater(90);
    hasExcept = false;
    try {
        reclaimer.useWater(1);
    } catch (LifeCriticalError const &error) {
        hasExcept = true;
        cr_assert(std::strcmp(error.what(),
            "Cannot use water, not enough in the reclaimer.") == 0);
        cr_assert(error.getComponent() == "WaterReclaimer");
    }
    cr_assert(hasExcept);

    hasExcept = false;
    try {
        reclaimer.useWater(-1);
    } catch (UserError const &error) {
        cr_assert(std::strcmp(error.what(), "Water use should be positif.") ==
        0);
        cr_assert(error.getComponent() == "WaterReclaimer");
        hasExcept = true;
    }
    cr_assert(hasExcept);

    WaterReclaimer otherReclaimer;
    hasExcept = false;
    try {
        otherReclaimer.useWater(5);
    } catch (UserError const &error) {
        cr_assert(std::strcmp(error.what(),
            "Cannot use water if the reclaimer hasn't started.") == 0);
        cr_assert(error.getComponent() == "WaterReclaimer");
        hasExcept = true;
    }
    cr_assert(hasExcept);
}

Test(Oxygenator, oxygenator)
{
    Oxygenator oxygenator;
    bool hasExcept = false;

    try {
        oxygenator.generateOxygen();
        oxygenator.useOxygen(5);
    } catch (LifeCriticalError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "Oxygenator");
        cr_assert(std::strcmp(error.what(), "Not enough oxygen to live.") == 0);
    }
    cr_assert(hasExcept);
    hasExcept = false;
    try {
        for (int i = 0; i < 8; ++i)
            oxygenator.generateOxygen();
        for (int i = 0; i < 8; ++i)
            oxygenator.useOxygen(10);
    } catch (MissionCriticalError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "Oxygenator");
        cr_assert(std::strcmp(error.what(),
            "Not enough oxygen to continue the mission.") == 0);
    }
    cr_assert(hasExcept);
}

Test(Engine, engine)
{
    Engine engine(3);
    bool hasExcept = false;

    try {
        engine.goTorward(10, 10);
    } catch (UserError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "Engine");
        cr_assert(std::strcmp(error.what(),
            "Cannot reach destination (10, 10).") == 0);
    }
    cr_assert(hasExcept);
    engine.goTorward(2, 2);
    hasExcept = false;
    try {
        engine.goTorward(7, 8);
    } catch (UserError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "Engine");
        cr_assert(std::strcmp(error.what(),
            "Cannot reach destination (7, 8).") == 0);
    }
    cr_assert(hasExcept);
    hasExcept = false;
    try {
        engine.goTorward(9, 8);
    } catch (UserError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "Engine");
        cr_assert(std::strcmp(error.what(),
            "Cannot reach destination (9, 8).") == 0);
    }
    cr_assert(hasExcept);
    hasExcept = false;
    try {
        engine.goTorward(-10, 7);
    } catch (UserError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "Engine");
        cr_assert(std::strcmp(error.what(),
            "Cannot reach destination (-10, 7).") == 0);
    }
    cr_assert(hasExcept);
}

Test(AtmosphereRegulator, atmosphere_regulator)
{
    bool hasExcept = false;
    try {
        AtmosphereRegulator regulator;
    } catch (NasaError const &error) {
        hasExcept = true;
        cr_assert(error.getComponent() == "AtmosphereRegulator");
        cr_assert(std::strcmp(error.what(), "Not implemented.") == 0);
    }
    cr_assert(hasExcept);
}