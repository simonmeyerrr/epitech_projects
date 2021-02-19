#ifndef CPP_ZIA_2019_MODULESMANAGER_HPP
#define CPP_ZIA_2019_MODULESMANAGER_HPP


#include <module/ALogger.hpp>
#include <module/ANetwork.hpp>
#include "../libloader/ModuleLoader.hpp"

class ModulesManager {
public:
    ~ModulesManager();
    ModulesManager();

    void start();
    void restart();
    void stop();
    void load(const api::JsonObject &config);

private:

    void loadLogger(const api::JsonObject &config);
    void loadNetwork(const api::JsonObject &config);
    void loadHttp(const api::JsonObject &config);
    void unload();
    void unloadLogger();
    void unloadNetwork();
    void unloadHttp();

    std::pair<std::unique_ptr<ModuleLoader>, api::module::ALogger *> _logger;
    std::pair<std::unique_ptr<ModuleLoader>, api::module::ANetwork *> _network;
    std::vector<std::pair<std::unique_ptr<ModuleLoader>, api::module::AHttp *>> _http;
};


#endif /* CPP_ZIA_2019_MODULESMANAGER_HPP */
