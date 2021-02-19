#include "JsonBuilder.hpp"

api::JsonType JsonBuilder::operator()() {
    return std::get<api::JsonType>(_workStack.top());
}

void JsonBuilder::openArray() {
    _workStack.push(Open{});
}

void JsonBuilder::closeArray() {
    api::JsonArray array{};
    while (!_workStack.top().index()) {
	array.insert(array.begin(), std::get<api::JsonType>(_workStack.top()));
	_workStack.pop();
    }
    _workStack.pop();
    _workStack.push(api::JsonType{array});
}

void JsonBuilder::openObject() {
    _workStack.push(Open{});
}

void JsonBuilder::closeObject() {
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

void JsonBuilder::string(std::wstring const &str) {
    _workStack.push(api::JsonType{api::JsonString{str}});
}

void JsonBuilder::number(double const &nb) {
    _workStack.push(api::JsonType{api::JsonNumber{nb}});
}

void JsonBuilder::boolean(bool const b) {
    _workStack.push(api::JsonType{api::JsonBool{b}});
}

void JsonBuilder::null() {
    _workStack.push(api::JsonType{api::JsonNull{}});
}

void JsonBuilder::begin() {
    _workStack = std::stack<std::variant<api::JsonType, Open>>{};
}
