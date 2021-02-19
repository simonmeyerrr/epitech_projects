#ifndef CPP_ZIA_2019_MODULELOADER_HPP
#define CPP_ZIA_2019_MODULELOADER_HPP

#include <memory>
#include <module/IModule.hpp>
#include "ILibLoader.hpp"

class ModuleLoader {
public:
    ~ModuleLoader();
    ModuleLoader();

    void loadModule(const api::JsonObject &config);
    void unloadModule();

    api::module::IModule *getModule() {return _module;}

private:
    std::unique_ptr<ILibLoader> _loader;
    api::module::IModule *_module;
};


#endif /* CPP_ZIA_2019_MODULELOADER_HPP */
