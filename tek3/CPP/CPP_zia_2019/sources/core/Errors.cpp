#include "Errors.hpp"

////////////////////////////////////////////////////////////////////////////////

ParsingError::ParsingError(std::string const &errorMessage, int const errorCode) noexcept : Error{"Parsing" + (errorMessage.size() ? " :: " + errorMessage : ""), errorCode} {
}

ParsingError::ParsingError(std::string &&errorMessage, int const errorCode) noexcept : ParsingError{errorMessage, errorCode} {
}

ParsingError::ParsingError(char const *const errorMessage, int const errorCode) noexcept : ParsingError{std::string{errorMessage}, errorCode} {
}

ParsingError::ParsingError(IError const &error) noexcept : Error{error} {
}

ParsingError::ParsingError(IError &&error) noexcept : Error{error} {
}

ParsingError::ParsingError(ParsingError const &error) noexcept : Error{error} {
}

ParsingError::ParsingError(ParsingError &&error) noexcept : Error{error} {
}

ParsingError::~ParsingError() {
}

ParsingError &ParsingError::operator=(ParsingError const &error) noexcept {
	return *dynamic_cast<ParsingError *>(&(*this = *dynamic_cast<IError const *>(&error)));
}

ParsingError &ParsingError::operator=(ParsingError &&error) noexcept {
	return *this = error;
}

////////////////////////////////////////////////////////////////////////////////

RuntimeError::RuntimeError(std::string const &errorMessage, int const errorCode) noexcept : Error{"Runtime" + (errorMessage.size() ? " :: " + errorMessage : ""), errorCode} {
}

RuntimeError::RuntimeError(std::string &&errorMessage, int const errorCode) noexcept : RuntimeError{errorMessage, errorCode} {
}

RuntimeError::RuntimeError(char const *const errorMessage, int const errorCode) noexcept : RuntimeError{std::string{errorMessage}, errorCode} {
}

RuntimeError::RuntimeError(IError const &error) noexcept : Error{error} {
}

RuntimeError::RuntimeError(IError &&error) noexcept : Error{error} {
}

RuntimeError::RuntimeError(RuntimeError const &error) noexcept : Error{error} {
}

RuntimeError::RuntimeError(RuntimeError &&error) noexcept : Error{error} {
}

RuntimeError::~RuntimeError() {
}

RuntimeError &RuntimeError::operator=(RuntimeError const &error) noexcept {
	return *dynamic_cast<RuntimeError *>(&(*this = *dynamic_cast<IError const *>(&error)));
}

RuntimeError &RuntimeError::operator=(RuntimeError &&error) noexcept {
	return *this = error;
}

////////////////////////////////////////////////////////////////////////////////

SystemError::SystemError(std::string const &errorMessage, int const errorCode) noexcept : Error{"System" + (errorMessage.size() ? " :: " + errorMessage : ""), errorCode} {
}

SystemError::SystemError(std::string &&errorMessage, int const errorCode) noexcept : SystemError{errorMessage, errorCode} {
}

SystemError::SystemError(char const *const errorMessage, int const errorCode) noexcept : SystemError{std::string{errorMessage}, errorCode} {
}

SystemError::SystemError(IError const &error) noexcept : Error{error} {
}

SystemError::SystemError(IError &&error) noexcept : Error{error} {
}

SystemError::SystemError(SystemError const &error) noexcept : Error{error} {
}

SystemError::SystemError(SystemError &&error) noexcept : Error{error} {
}

SystemError::~SystemError() {
}

SystemError &SystemError::operator=(SystemError const &error) noexcept {
return *dynamic_cast<SystemError *>(&(*this = *dynamic_cast<IError const *>(&error)));
}

SystemError &SystemError::operator=(SystemError &&error) noexcept {
return *this = error;
}


