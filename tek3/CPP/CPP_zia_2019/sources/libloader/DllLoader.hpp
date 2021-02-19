#ifndef CPP_ZIA_2019_DLLLOADER_HPP
#define CPP_ZIA_2019_DLLLOADER_HPP

#ifdef WIN32

#include <iostream>
#include <string>
#include <windows.h>

#include "ILibLoader.hpp"

class DllLoader : public ILibLoader {
public:
    virtual ~DllLoader() override {unloadLibrary();}
    DllLoader() : _lib(nullptr) {}


    void loadLibrary(const std::string &file) override
    {
        if (_lib)
            unloadLibrary();
        _lib = LoadLibrary(file.c_str());
        if (!_lib) {
            _lib = nullptr;
            throw std::runtime_error("Could not load " + file);
        }
    }

    void unloadLibrary() override
    {
        if (_lib) {
            // TODO find function on windows to unload library
            //dlclose(_lib);
        }
        _lib = nullptr;
    }

    void *getFunc(const std::string &name) override
    {
        FARPROC func = GetProcAddress(_lib, name.c_str());

        if (!func)
            throw std::runtime_error("Could not find " + name + " in library");
        return static_cast<void *>(func);
    }

protected:
    HMODULE _lib;
};

#endif /* WIN32 */

#endif /* CPP_ZIA_2019_DLLLOADER_HPP */
