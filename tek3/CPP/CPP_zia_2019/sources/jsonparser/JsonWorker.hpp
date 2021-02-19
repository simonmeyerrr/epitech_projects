#ifndef JSONWORKER_HPP_
#define JSONWORKER_HPP_

#include <string>

struct JsonWorker {
    explicit JsonWorker() noexcept = default;
    JsonWorker(JsonWorker const &) noexcept = delete;
    explicit JsonWorker(JsonWorker &&) noexcept = default;
    ~JsonWorker() noexcept = default;
    virtual void openArray() = 0;
    virtual void closeArray() = 0;
    virtual void openObject() = 0;
    virtual void closeObject() = 0;
    virtual void string(std::wstring const &) = 0;
    virtual void number(double const &) = 0;
    virtual void boolean(bool const) = 0;
    virtual void null() = 0;
    virtual void arraySeparator();
    virtual void objectSeparator();
    virtual void pair();
    virtual void begin();
    virtual void end();
    using ReturnType = void;
};

#endif
