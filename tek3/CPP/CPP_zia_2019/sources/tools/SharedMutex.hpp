#ifndef SHAREDMUTEX_HPP_
#define SHAREDMUTEX_HPP_

#include <deque>
#include <algorithm>

#include "Mutex.hpp"

////////////////////////////////////////////////////////////////////////////////
#ifdef WIN32

#include <shared_mutex>
using SharedMutex = std::shared_mutex;
using RLocker = std::shared_lock<std::shared_mutex>;
using WLocker = std::unique_lock<std::shared_mutex>;
#else
class SharedMutex {
public:
    void wlock() const noexcept;
    void rlock() const noexcept;
    void unlock() const noexcept;
private:
    enum State {
	free,
	read,
	write
    };
    Mutex _m;
    mutable State _state{State::free};
    mutable std::deque<std::size_t> _owners;
};

////////////////////////////////////////////////////////////////////////////////

class WLocker {
public:
    explicit WLocker(SharedMutex const &) noexcept;
    ~WLocker() noexcept;
private:
    SharedMutex const &_m;
};

////////////////////////////////////////////////////////////////////////////////

class RLocker {
public:
    explicit RLocker(SharedMutex const &) noexcept;
    ~RLocker() noexcept;
private:
    SharedMutex const &_m;
};
#endif

////////////////////////////////////////////////////////////////////////////////

#endif
