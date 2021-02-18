/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** IMonitorModule.cpp
*/

#include <iostream>
#include "IMonitorModule.hpp"
#include "InfoModule.hpp"
#include "CpuModule.hpp"
#include "MemoryModule.hpp"
#include "NetworkModule.hpp"
#include "ReportsModule.hpp"
#include "BatteryModule.hpp"
#include "DanModule.hpp"

static IMonitorModule *createMonitorNormal(Types::Modules mode)
{
    switch (mode) {
    case Types::INFO :
        return (new InfoModule);
    case Types::CPU :
        return (new CpuModule);
    case Types::MEMORY :
        return (new MemoryModule);
    case Types::NETWORK :
        return (new NetworkModule);
    case Types::REPORTS :
        return (new ReportsModule);
    case Types::BATTERY:
        return (new BatteryModule);
    case Types::DAN :
        return (new DanModule);
    case Types::NONE :
        return (nullptr);
    }
    return (nullptr);
}

static IMonitorModule *createMonitorOffsetLeft(Types::Modules mode)
{
    switch (mode) {
    case Types::INFO :
        return (createMonitorNormal(Types::NONE));
    case Types::CPU :
        return (createMonitorNormal(Types::INFO));
    case Types::MEMORY :
        return (createMonitorNormal(Types::CPU));
    case Types::NETWORK :
        return (createMonitorNormal(Types::MEMORY));
    case Types::REPORTS :
        return (createMonitorNormal(Types::NETWORK));
    case Types::BATTERY :
        return (createMonitorNormal(Types::REPORTS));
    case Types::DAN :
        return (createMonitorNormal(Types::BATTERY));
    case Types::NONE :
        return (createMonitorNormal(Types::DAN));
    }
    return (nullptr);
}

static IMonitorModule *createMonitorOffsetRight(Types::Modules mode)
{
    switch (mode) {
    case Types::INFO :
        return (createMonitorNormal(Types::CPU));
    case Types::CPU :
        return (createMonitorNormal(Types::MEMORY));
    case Types::MEMORY :
        return (createMonitorNormal(Types::NETWORK));
    case Types::NETWORK :
        return (createMonitorNormal(Types::REPORTS));
    case Types::REPORTS :
        return (createMonitorNormal(Types::BATTERY));
    case Types::BATTERY :
        return (createMonitorNormal(Types::DAN));
    case Types::DAN :
        return (createMonitorNormal(Types::NONE));
    case Types::NONE :
        return (createMonitorNormal(Types::INFO));
    }
    return (nullptr);
}

IMonitorModule *createMonitorModule(Types::Modules mode, Types::Offset offset)
{
    switch (offset) {
    case Types::LEFT :
        return (createMonitorOffsetLeft(mode));
    case Types::NORMAL:
        return (createMonitorNormal(mode));
    case Types::RIGHT :
        return (createMonitorOffsetRight(mode));
    }
    return (nullptr);
}
