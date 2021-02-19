#include "JsonPrinter.hpp"

JsonPrinter::JsonPrinter(bool const colors, bool const indentation, std::size_t const tabSize) : _colors{colors}, _indentation{indentation}, _tabSize{tabSize} {
}

JsonPrinter::JsonPrinter(std::wostream &out, bool const colors, bool const indentation, std::size_t const tabSize) : _colors{colors}, _indentation{indentation}, _tabSize{tabSize}, _out{out} {
}

void JsonPrinter::red(bool const light) {
    if (!_colors)
	return;
    _out << (light ? L"\033[1;31m" : L"\033[0;31m");
}

void JsonPrinter::green(bool const light) {
    if (!_colors)
	return;
    _out << (light ? L"\033[1;32m" : L"\033[0;32m");
}

void JsonPrinter::yellow(bool const light) {
    if (!_colors)
	return;
    _out << (light ? L"\033[1;33m" : L"\033[0;33m");
}

void JsonPrinter::blue(bool const light) {
    if (!_colors)
	return;
    _out << (light ? L"\033[1;34m" : L"\033[0;34m");
}

void JsonPrinter::purple(bool const light) {
    if (!_colors)
	return;
    _out << (light ? L"\033[1;35m" : L"\033[0;35m");
}

void JsonPrinter::cyan(bool const light) {
    if (!_colors)
	return;
    _out << (light ? L"\033[1;36m" : L"\033[0;36m");
}

void JsonPrinter::white(bool const light) {
    if (!_colors)
	return;
    _out << (light ? L"\033[1;37m" : L"\033[0;37m");
}

void JsonPrinter::tabLevel() {
    if (!_indentation)
	return;
    for (std::size_t level = 0; _level > level; ++level)
	for (std::size_t i = 0; i < _tabSize; ++i)
	    _out << L' ';
}

void JsonPrinter::openArray() {
    red();
    _out << L'[';
    white(false);
}

void JsonPrinter::closeArray() {
    red();
    _out << L']';
    white(false);
}

void JsonPrinter::openObject() {
    ++_level;
    blue();
    _out << L'{';
    white(false);
    if (_indentation)
	_out << L'\n';
    _indent = true;
}

void JsonPrinter::closeObject() {
    if (!_level)
	abort();
    --_level;
    white(false);
    if (_indentation)
	_out << L'\n';
    tabLevel();
    blue();
    _out << L'}';
    white(false);
}

void JsonPrinter::string(std::wstring const &str) {
    if (_indent)
	tabLevel();
    cyan();
    _out << L'\"';
    white();
    _out << str;
    cyan();	
    _out << L'\"';
    white(false);
}

void JsonPrinter::number(double const &nb) {
    if (_indent)
	tabLevel();
    purple();
    _out << nb;
    white(false);
}

void JsonPrinter::boolean(bool const b) {
    if (_indent)
	tabLevel();
    green();
    _out << (b ? L"true" : L"false");
    white(false);
}

void JsonPrinter::null() {
    if (_indent)
	tabLevel();
    yellow();
    _out << L"null";
    white(false);
}

void JsonPrinter::arraySeparator() {
    red();
    _out << L',';
    white(false);
    if (_indentation)
	_out << L' ';
}

void JsonPrinter::objectSeparator() {
    blue();
    _out << L',';
    white(false);
    if (_indentation)
	_out << L" \n";
    _indent = true;
}

void JsonPrinter::pair() {
    blue();
    _out << L':';
    white(false);
    if (_indentation)
	_out << L' ';
    _indent = false;
}

void JsonPrinter::begin() {
    _indent = true;
    _level = 0;
}

void JsonPrinter::end() {
    white(false);
    if (_indentation)
	_out << std::endl;
}
