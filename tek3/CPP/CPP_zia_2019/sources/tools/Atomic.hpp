#ifndef ATOMIC_HPP_
#define ATOMIC_HPP_

#include "Mutex.hpp"

////////////////////////////////////////////////////////////////////////////////

template<typename T> class Atomic {
public:
    Atomic() noexcept : _t{} {}
    Atomic(T const &t) : _t{std::move(t)} {}
    explicit Atomic(T &&t) noexcept : _t{std::move(t)} {}
    operator T() const noexcept {
	return std::move(load());
    }
    T load() const noexcept {
	T r;
	{
		Locker l{ _m };
	    r = _t;
	}
	return std::move(r);
    }
    void store(T const &t) noexcept {
	Locker lock{_m};
	_t = t;
    }
    void store(T &&t) noexcept {
        store(t);
    }
private:
    mutable Mutex _m;
    T _t;
};

////////////////////////////////////////////////////////////////////////////////

#endif
