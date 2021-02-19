#ifndef CPP_ZIA_2019_CONSOLELOGGER_HPP
#define CPP_ZIA_2019_CONSOLELOGGER_HPP

#include <iostream>
#include <module/ALogger.hpp>
#include <Atomic.hpp>

class ConsoleLogger : public api::module::ALogger {
public:
    ~ConsoleLogger() override = default;
    ConsoleLogger() = default;

    void setConfig(const api::JsonObject &config) override;
    api::String getName() const override;
    void log(const api::String &message, Level lvl) override;

private:
    void print(std::ostream &stream, const api::String &message, const api::String &color = "");

    Atomic<bool> _debug = true;
    Mutex _m;
};

#endif /* CPP_ZIA_2019_CONSOLELOGGER_HPP */
