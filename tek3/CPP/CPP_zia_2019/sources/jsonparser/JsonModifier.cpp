#include <functional>
#include <sstream>
#include <locale>
#include <iostream>

#include "JsonModifier.hpp"
#include "JsonError.hpp"

JsonModifier::JsonModifier(std::string const &key, std::string const &value) : _key{key}, _value{value}, _extract{"__EXTRACT" == value} {
    std::stringstream tmp{_key};
    tmp.imbue(std::locale(tmp.getloc(), new dtSSpc{}));
    while (tmp >> _key)
	_path.push_back(_key);
}

api::JsonType JsonModifier::operator()() {
    return std::get<api::JsonType>(_workStack.top());
}

void JsonModifier::openArray() {
    if (_replace)
	_replace = false;
    _workStack.push(Open{});
}

void JsonModifier::closeArray() {
    api::JsonArray array{};
    while (!_workStack.top().index()) {
	array.insert(array.begin(), std::get<api::JsonType>(_workStack.top()));
	_workStack.pop();
    }
    _workStack.pop();
    _workStack.push(api::JsonType{array});
}

void JsonModifier::openObject() {
    if (_replace)
	_replace = false;
    _workStack.push(Open{});
}

void JsonModifier::closeObject() {
    api::JsonObject object{};
    api::JsonType value{};
    while (!_workStack.top().index()) {
	value = std::get<api::JsonType>(_workStack.top());
	_workStack.pop();
	object[std::get<api::JsonString>(std::get<api::JsonType>(_workStack.top())._)] = value;
	_workStack.pop();
    }
    _workStack.pop();
    _workStack.push(api::JsonType{object});
}

void JsonModifier::string(std::wstring const &str) {
    if (_replace) {
	_replace = false;
	_workStack.push(api::JsonType{api::JsonString{_value.begin(), _value.end()}});
    } else
	_workStack.push(api::JsonType{api::JsonString{str}});

}

void JsonModifier::number(double const &nb) {
    if (_replace) {
	_replace = false;
	_workStack.push(api::JsonType{api::JsonNumber{std::stof(_value)}});
    } else
	_workStack.push(api::JsonType{api::JsonNumber{nb}});
}

void JsonModifier::boolean(bool const b) {
    if (_replace) {
	_replace = false;
	std::function<bool(std::string const &, std::string const &)> cmp = [](std::string const &f, std::string const &s){return std::equal(f.cbegin(), f.cend(), s.cbegin(), s.cend(), [](char const f, char const s) {return tolower(f) == tolower(s);});};
	bool b;
	if (cmp("TruE", _value) || "1" == _value)
	    b = true;
	else if (cmp("fAlSe", _value) || "0" == _value)
	    b = false;
	else
	    error("expecting boolean");
	_workStack.push(api::JsonType{api::JsonBool{b}});
    } else
	_workStack.push(api::JsonType{api::JsonBool{b}});
}

void JsonModifier::null() {
    if (_replace) {
	_replace = false;
	if ([](std::string const &f, std::string const &s){return std::equal(f.cbegin(), f.cend(), s.cbegin(), s.cend(), [](char const f, char const s) {return tolower(f) == tolower(s);});}("NuLL", _value))
	    _workStack.push(api::JsonType{api::JsonNull{}});
	else
	    error("expecting null");
    } else
	_workStack.push(api::JsonType{api::JsonNull{}});
}

void JsonModifier::begin() {
    _workStack = std::stack<std::variant<api::JsonType, Open>>{};
}

void JsonModifier::pair() {
    if (std::get<api::JsonString>(std::get<api::JsonType>(_workStack.top())._) == api::JsonString{_key.begin(), _key.end()})
	_replace = true;
}
