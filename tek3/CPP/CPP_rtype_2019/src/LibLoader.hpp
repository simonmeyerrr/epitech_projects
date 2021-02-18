//
// Created by arnaud on 24/11/2019.
//

#ifndef CPP_RTYPE_2019_LIBLOADER_HPP
#define CPP_RTYPE_2019_LIBLOADER_HPP

#include <iostream>
#include <string>
#include <exception>
#include "server/core/Entities/IEntity.hpp"

#ifdef WIN32
	#include "socket/socket_c/Includes.hpp"
	#include <stdio.h>
#else
	#include <dlfcn.h>
#endif

class LibLoader {
public:
    ~LibLoader()
    {
#ifdef WIN32
#else
        dlclose(_lib);
#endif
    }

    explicit LibLoader(const std::string &file)
        : _lib(nullptr), _initer(nullptr)
    {
#ifdef WIN32
		_lib = LoadLibrary(file.c_str());
#else
		_lib = dlopen(file.c_str(), RTLD_LAZY);
#endif
        if(_lib == nullptr) {
            std::cout << "could not open lib " << file << std::endl;
            throw std::exception();
        }

#ifdef WIN32
		_initer = GetProcAddress(_lib, "init");
#else
		_initer = dlsym(_lib, "init");
#endif
        if (_initer == nullptr) {
            std::cout << "could not get initer " << file << std::endl;
            throw std::exception();
        }
    }

    IEntity *createInstance(int posY) {
        auto func = (IEntity *(*)(int posY))(_initer);
        return func(posY);
    }

private:
#ifdef WIN32
	HMODULE _lib;
	FARPROC _initer;
#else
	void * _lib;
	void *_initer;
#endif
};

#endif //CPP_RTYPE_2019_LIBLOADER_HPP
