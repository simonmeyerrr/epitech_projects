#ifndef JSONMODIFIER_HPP_
#define JSONMODIFIER_HPP_

#include <stack>

#include "Types.hpp"
#include "JsonWorker.hpp"

struct JsonModifier : JsonWorker {
    JsonModifier(std::string const &, std::string const &value = "__EXTRACT");
    JsonModifier() = default;
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
    void pair();
    struct Open {};
    std::stack<std::variant<api::JsonType, Open>> _workStack;
    using ReturnType = api::JsonType;
    std::string _key, _value;
    std::vector<std::string> _path;
    std::size_t _pathMtchr = 0;
    bool _extract, _extracting = false, _replace = false;
};

struct dtSSpc : std::ctype<char> {
    dtSSpc() : std::ctype<char>(tbl()) {
    }
    
    static mask const *tbl() noexcept {
	static mask rc[table_size];
	rc['.'] = std::ctype_base::space;
	return &rc[0];
    }
};

#endif
