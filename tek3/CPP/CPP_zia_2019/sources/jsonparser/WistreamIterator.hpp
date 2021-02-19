#ifndef WISTREAMITERATOR_HPP_
#define WISTREAMITERATOR_HPP_

#include <fstream>

template<typename T> class WistreamIterator {
public:
    WistreamIterator(std::wifstream &stream) noexcept : _stream{&stream} {
        ++*this;
    }

    WistreamIterator(std::wifstream &stream, T const &t) noexcept : _stream{&stream}, _t{t} {
    }

    WistreamIterator() noexcept : _stream{nullptr} {
    }

    bool operator==(WistreamIterator<T> const &other) const noexcept {
        return status() == other.status();
    }

    bool operator!=(WistreamIterator<T> const &other) const noexcept {
        return !(*this == other);
    }

    WistreamIterator<T> operator++(int) noexcept {
        T t = _t;
        _t = _stream->get();
        return WistreamIterator<T>{*_stream, t};
    }

    WistreamIterator<T> &operator++() noexcept {
	_t = _stream->get();
        return *this;
    }

    T operator*() const noexcept {
        return _t;
    }

private:
    long int status() const noexcept {
        return _stream && _stream->good() ? (long int)_stream->tellg() : -1;
    }

    std::wifstream *_stream;
    T _t;
};

#endif
