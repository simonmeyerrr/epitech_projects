#include <iostream>
#include <ctime>
#include <iomanip>
#include "ConsoleLogger.hpp"
#include "ModuleLoggable.hpp"

MODULE_EXPORTER(ConsoleLogger)

void ConsoleLogger::setConfig(const api::JsonObject &config)
{
    try {
        bool d = config.at(L"debug").as<api::JsonBool>();
        _debug.store(d);
    } catch (...) {
        _debug.store(true);
    }
}

void ConsoleLogger::log(const api::String &message, api::module::ALogger::Level lvl)
{
    switch (lvl) {
        case LEVEL_FATAL:
            print(std::cerr, message, "\033[1;31m");
            //abort();
            break;
        case LEVEL_ERROR:
            print(std::cerr, message, "\033[0;31m");
            break;
        case LEVEL_WARNING:
            print(std::cout, message, "\033[0;33m");
            break;
        case LEVEL_INFO:
            print(std::cout, message, "\033[0;34m");
            break;
        case LEVEL_DEBUG:
            if (_debug)
                print(std::cout, message, "");
            break;
        default:
            print(std::cout, message, "");
    }
}

void ConsoleLogger::print(std::ostream &stream, const api::String &message, const api::String &color)
{
    std::time_t result = std::time(nullptr);

    Locker l{_m};
    stream << color << std::put_time(std::localtime(&result), "%F %T") << " " << message << "\033[0m" << std::endl;
}

api::String ConsoleLogger::getName() const
{
    return "ConsoleLogger";
}
