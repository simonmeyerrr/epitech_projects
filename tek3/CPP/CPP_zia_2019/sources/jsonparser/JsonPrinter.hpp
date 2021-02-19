#ifndef JSONPRINTER_HPP_
#define JSONPRINTER_HPP_

#include <iostream>

#include "JsonWorker.hpp"

struct JsonPrinter : JsonWorker {
    JsonPrinter(bool const colors = true, bool const indent = true, std::size_t const tabSize = 4);
    JsonPrinter(std::wostream &out, bool const colors = true, bool const indent = true, std::size_t const tabSize = 4);
    void red(bool const light = true);
    void green(bool const light = true);
    void yellow(bool const light = true);
    void blue(bool const light = true);
    void purple(bool const light = true);
    void cyan(bool const light = true);
    void white(bool const light = true);
    void tabLevel();
    void openArray();
    void closeArray();
    void openObject();
    void closeObject();
    void string(std::wstring const&);
    void number(double const&);
    void boolean(bool const);
    void null();
    void arraySeparator();
    void objectSeparator();
    void pair();
    void begin();
    void end();    
    bool _indent = true;
    std::size_t _level = 0;
    bool const _colors, _indentation;
    std::size_t const _tabSize;
    std::wostream &_out = std::wcout;
};

#endif
