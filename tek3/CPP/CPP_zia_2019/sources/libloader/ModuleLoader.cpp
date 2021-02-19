#include "DllLoader.hpp"
#include "LibLoader.hpp"
#include "ModuleLoader.hpp"
#include "../core/IError.hpp"

ModuleLoader::~ModuleLoader()
{
    unloadModule();
}

ModuleLoader::ModuleLoader()
    : _loader(nullptr), _module(nullptr)
{
#ifdef WIN32
    _loader = std::make_unique<DllLoader>();
#else
    _loader = std::make_unique<LibLoader>();
#endif
}

void ModuleLoader::loadModule(const api::JsonObject &config)
{
    unloadModule();

    std::wstring path;
    std::wstring name;

    try {
        path = config.at(L"path").as<api::JsonString>();
        name = config.at(L"name").as<api::JsonString>();
    } catch (...) {
        throw Error("Missing path and/or name in config");
    }

    std::string final_path = std::string(path.begin(), path.end()) + LIB_PREFIX + std::string(name.begin(), name.end()) + LIB_SUFFIX;

    try {
        _loader->loadLibrary(final_path);
        _loader->getFuncCast<void (*)()>("loadModule")();
        _module = _loader->getFuncCast<api::module::IModule *(*)()>("getModule")();
        _module->setConfig(config);
    } catch (const IError &e) {
        unloadModule();
        throw Error(e);
    }
}

void ModuleLoader::unloadModule()
{
    _module = nullptr;

    try {
        _loader->getFuncCast<void (*)()>("unloadModule")();
    } catch (...) {}
    try {
        _loader->unloadLibrary();
    } catch (...) {}
}