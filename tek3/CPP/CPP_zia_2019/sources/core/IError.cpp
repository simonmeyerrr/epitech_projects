#include "IError.hpp"

////////////////////////////////////////////////////////////////////////////////

    IError::IError() noexcept : std::exception{} {
    }

    IError::~IError() noexcept {
    }

////////////////////////////////////////////////////////////////////////////////

    Error::Error(std::string const &errorMessage, int const errorCode) noexcept : IError{}, _errorMessage{errorMessage}, _errorCode{errorCode} {
    }

    Error::Error(std::string &&errorMessage, int const errorCode) noexcept : Error{errorMessage, errorCode} {
    }

    Error::Error(char const *const errorMessage, int const errorCode) noexcept : Error{std::string{errorMessage}, errorCode} {
    }

    Error::Error(IError const &error) noexcept : IError{}, _errorMessage{error.ErrorMessage()}, _errorCode{error.ErrorCode()} {
    }

    Error::Error(IError &&error) noexcept : Error{error} {
    }

    Error::Error(Error const &error) noexcept : Error{*dynamic_cast<IError const *>(&error)} {
    }

    Error::Error(Error &&error) noexcept : Error{error} {
    }

    Error::~Error() noexcept {
    }

    IError &Error::operator=(IError const &error) noexcept {
	_errorMessage = error.ErrorMessage();
	_errorCode = error.ErrorCode();
	return *this;
    }

    IError &Error::operator=(IError &&error) noexcept {
	return *this = error;
    }

    Error &Error::operator=(Error const &error) noexcept {
	return *dynamic_cast<Error *>(&(*this = *dynamic_cast<IError const *>(&error)));
    }

    Error &Error::operator=(Error &&error) noexcept {
	return *this = error;
    }

    const char *Error::what() const noexcept {
	return _errorMessage.c_str();
    }

    std::string const &Error::ErrorMessage() const noexcept {
	return _errorMessage;
    }

    int Error::ErrorCode() const noexcept {
	return _errorCode;
    }

////////////////////////////////////////////////////////////////////////////////
