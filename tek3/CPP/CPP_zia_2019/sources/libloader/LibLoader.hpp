#ifndef CPP_ZIA_2019_LIBLOADER_HPP
#define CPP_ZIA_2019_LIBLOADER_HPP

#ifndef WIN32

#include <iostream>
#include <string>
#include <dlfcn.h>

#include "ILibLoader.hpp"
#include "../core/Errors.hpp"

class LibLoader : public ILibLoader {
public:
    virtual ~LibLoader() override {unloadLibrary();}
    LibLoader() : _lib(nullptr) {}


    void loadLibrary(const std::string &file) override
    {
        char *error;

        if (_lib)
            unloadLibrary();
        _lib = dlopen(file.c_str(), RTLD_LAZY);
        error = dlerror();
        if (!_lib || error) {
            _lib = nullptr;
            throw Error(error);
        }
    }

    void unloadLibrary() override
    {
        char *error;

        if (_lib) {
            dlclose(_lib);
            error = dlerror();
            if (error)
                throw Error(error);
        }
        _lib = nullptr;
    }

    void *getFunc(const std::string &name) override
    {
        void *func = dlsym(_lib, name.c_str());
        char *error = dlerror();

        if (!func || error)
            throw Error(error);
        return func;
    }

protected:
    void *_lib;
};

#endif /* WIN32 */

#endif /* CPP_ZIA_2019_LIBLOADER_HPP */
