#ifndef CPP_ZIA_2019_ILIBLOADER_HPP
#define CPP_ZIA_2019_ILIBLOADER_HPP

#ifdef WIN32
    #define LIB_PREFIX ""
    #define LIB_SUFFIX ".dll"
#else
    #define LIB_PREFIX "lib"
    #define LIB_SUFFIX ".so"
#endif

#include <string>

class ILibLoader {
public:
    virtual ~ILibLoader() = default;

    virtual void loadLibrary(const std::string &file) = 0;
    virtual void unloadLibrary() = 0;

    virtual void *getFunc(const std::string &name) = 0;

    template <typename T>
    T getFuncCast(const std::string &name)
    {
        return (T)(getFunc(name));
    }

};

#endif /* CPP_ZIA_2019_ILIBLOADER_HPP */
