#ifndef CPP_ZIA_2019_MODULELOGGABLE_HPP
#define CPP_ZIA_2019_MODULELOGGABLE_HPP

#include <module/ALogger.hpp>
#include "Mutex.hpp"

#ifdef WIN32
    #define MY_EXPORT_LIB __declspec(dllexport)
#else
    #define MY_EXPORT_LIB
#endif

#define MODULE_EXPORTER(type) extern "C" { \
    api::module::IModule *module = nullptr; \
    MY_EXPORT_LIB void loadModule() \
    { \
	    delete module; \
        module = new type(); \
    } \
    MY_EXPORT_LIB  void unloadModule() \
    { \
	    delete module; \
        module = nullptr; \
    } \
    MY_EXPORT_LIB api::module::IModule *getModule() \
    { \
	    return module; \
    } \
}\

class ModuleLoggable {
public:
    virtual ~ModuleLoggable() = default;
    ModuleLoggable() : _m(), _l(nullptr) {}

    void updateLogger(api::module::ALogger *l)
    {
        Locker lock{_m};
        _l = l;
    }

    void log(const api::String &message, api::module::ALogger::Level lvl = api::module::ALogger::LEVEL_INFO)
    {
        Locker lock{_m};

        if (_l)
            _l->log(message, lvl);
    }

private:
    Mutex _m;
    api::module::ALogger *_l;
};

#endif //CPP_ZIA_2019_MODULELOGGABLE_HPP
