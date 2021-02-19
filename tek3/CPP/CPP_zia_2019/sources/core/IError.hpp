#ifndef IERROR_HPP_
#define IERROR_HPP_

#include <stdexcept>
#include <string>

////////////////////////////////////////////////////////////////////////////////

    enum ERRORCODE {
	SUCCESS = 0,
	SYSTEMERROR = 132,
	UNDEFINEDERROR,
        PARSINGERROR,
        RUNTIMEERROR
    };

////////////////////////////////////////////////////////////////////////////////

    class IError : public std::exception {
    public:
        explicit IError() noexcept;
        IError(IError const &) noexcept = delete;
        explicit IError(IError &&) noexcept = delete;
	virtual ~IError() noexcept;

	virtual IError &operator=(IError const &) noexcept = 0;
	virtual IError &operator=(IError &&) noexcept = 0;

	virtual char const *what() const noexcept = 0;
	virtual std::string const &ErrorMessage() const noexcept = 0;
	virtual int ErrorCode() const noexcept = 0;

    protected:
    };

////////////////////////////////////////////////////////////////////////////////

    class Error : public IError {
    public:
	explicit Error(std::string const &errorMessage = "", int const errorCode = UNDEFINEDERROR) noexcept;
	explicit Error(std::string &&, int const) noexcept;
	explicit Error(char const *const, int const) noexcept;
	Error(IError const &) noexcept;
	explicit Error(IError &&) noexcept;
        Error(Error const &) noexcept;
	explicit Error(Error &&) noexcept;
	virtual ~Error() noexcept override;

	virtual IError &operator=(IError const &) noexcept override final;
        virtual IError &operator=(IError &&) noexcept override final;
	Error &operator=(Error const &) noexcept;
	Error &operator=(Error &&) noexcept;

	virtual char const *what() const noexcept override final;
	virtual std::string const &ErrorMessage() const noexcept override final;
	virtual int ErrorCode() const noexcept override final;

    protected:
	std::string _errorMessage;
	int _errorCode;
    };

////////////////////////////////////////////////////////////////////////////////

#endif
