#ifndef JSONBUILDER_HPP_
#define JSONBUILDER_HPP_

#include <stack>

#include "Types.hpp"
#include "JsonWorker.hpp"

struct JsonBuilder : JsonWorker {
    api::JsonType operator()();
    void openArray();
    void closeArray();
    void openObject();
    void closeObject();
    void string(std::wstring const &);
    void number(double const &);
    void boolean(bool const);
    void null();
    void begin();
    struct Open {};
    std::stack<std::variant<api::JsonType, Open>> _workStack;
    using ReturnType = api::JsonType;
};

#endif
