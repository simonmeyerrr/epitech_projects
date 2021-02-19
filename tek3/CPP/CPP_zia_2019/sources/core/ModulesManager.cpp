#include <iostream>
#include "ModulesManager.hpp"
#include "Errors.hpp"

ModulesManager::~ModulesManager()
{
    unload();
}

ModulesManager::ModulesManager()
        : _logger(nullptr, nullptr), _network(nullptr, nullptr), _http()
{
    _logger.first = std::make_unique<ModuleLoader>();
    _network.first = std::make_unique<ModuleLoader>();
}

void ModulesManager::load(const api::JsonObject &config)
{
    bool running = _network.second ? _network.second->isRunning() : false;
    unload();
    loadLogger(config);
    loadHttp(config);
    loadNetwork(config);
    if (running && _network.second)
        _network.second->startServing();
}

void ModulesManager::start()
{
    if (_network.second) {
        _network.second->startServing();
    }
}

void ModulesManager::restart()
{
    stop();
    start();
}

void ModulesManager::stop()
{
    if (_network.second) {
        _network.second->stopServing();
        std::cout << "Stopped server" << std::endl;
    }
}

void ModulesManager::loadLogger(const api::JsonObject &config)
{
    try {
        _logger.first->loadModule(config.at(L"logger").as<api::JsonObject>());
        auto module = _logger.first->getModule();
        if (!module)
            throw Error("module not allocated");
        if (module->getType() != api::module::IModule::LOGGER)
            throw Error("this is not a logger module");
        _logger.second = dynamic_cast<api::module::ALogger *>(module);
        if (!_logger.second)
            throw Error("this is not a network module");
        if (_network.second)
            _network.second->setLogger(_logger.second);
        for (auto &item: _http) {
            if (item.second)
                item.second->setLogger(_logger.second);
        }
    } catch (const std::exception &e) {
        std::cerr << "\tFailed to load logger module: " << e.what() << std::endl;
        return;
    }
    auto &name = config.at(L"logger").as<api::JsonObject>().at(L"name").as<api::JsonString>();
    std::cout << "\tLogger module loaded: " << std::string(name.begin(), name.end()) << std::endl;
}

void ModulesManager::loadNetwork(const api::JsonObject &config)
{
    try {
        _network.first->loadModule(config.at(L"network").as<api::JsonObject>());
        auto module = _network.first->getModule();
        if (!module)
            throw Error("module not allocated");
        if (module->getType() != api::module::IModule::NETWORK)
            throw Error("this is not a network module");
        _network.second = dynamic_cast<api::module::ANetwork *>(module);
        if (!_network.second)
            throw Error("this is not a network module");
        _network.second->setLogger(_logger.second);
        std::vector<api::module::AHttp *> modules;
        for (auto &item: _http) {
            if (item.second)
                modules.emplace_back(item.second);
        }
        _network.second->setModules(modules);
    } catch (const std::exception &e) {
        std::cerr << "\tFailed to load network module: " << e.what() << std::endl;
        return;
    }
    auto &name = config.at(L"network").as<api::JsonObject>().at(L"name").as<api::JsonString>();
    std::cout << "\tNetwork module loaded: " << std::string(name.begin(), name.end()) << std::endl;
}

void ModulesManager::loadHttp(const api::JsonObject &config)
{
    try {
        auto &array = config.at(L"http").as<api::JsonArray>();
        for (auto &item: array) {
            _http.emplace_back(std::make_unique<ModuleLoader>(), nullptr);
            try {
                auto &cfg = item.as<api::JsonObject>();
                _http.back().first->loadModule(cfg);
                auto module = _http.back().first->getModule();
                if (!module)
                    throw Error("module not allocated");
                if (module->getType() != api::module::IModule::HTTP)
                    throw Error("this is not an http module");
                _http.back().second = dynamic_cast<api::module::AHttp *>(module);
                if (!_http.back().second)
                    throw Error("this is not an http module");
                _http.back().second->setLogger(_logger.second);
            } catch (const std::exception &e) {
                _http.pop_back();
                std::cerr << "\tFailed to load an http module: " << e.what() << std::endl;
                continue;
            }
            auto &name = item.as<api::JsonObject>().at(L"name").as<api::JsonString>();
            std::cout << "\tHttp module loaded: " << std::string(name.begin(), name.end()) << std::endl;
        }
    } catch (...) {
        std::cerr << "\tFailed to find http modules in config" << std::endl;
    }
}

void ModulesManager::unload()
{
    unloadNetwork();
    unloadHttp();
    unloadLogger();
}

void ModulesManager::unloadLogger()
{
    if (_network.second)
        _network.second->setLogger(nullptr);
    for (auto &http: _http) {
        if (http.second)
            http.second->setLogger(nullptr);
    }
    _logger.second = nullptr;
    _logger.first->unloadModule();
}

void ModulesManager::unloadNetwork()
{
    if (_network.second)
        _network.second->stopServing();
    _network.second = nullptr;
    _network.first->unloadModule();
}

void ModulesManager::unloadHttp()
{
    if (_network.second)
        _network.second->setModules({});
    for (auto &http: _http) {
        if (http.second)
            http.second = nullptr;
        http.first->unloadModule();
    }
    _http.clear();
}