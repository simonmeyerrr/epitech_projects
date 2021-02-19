#include "Mutex.hpp"

////////////////////////////////////////////////////////////////////////////////

#ifndef WIN32
void Mutex::lock() const noexcept {
    while (!cmpxchg(&_owner, 0, pthread_self()));
}

void Mutex::unlock() const noexcept {
    if (!cmpxchg(&_owner, pthread_self(), 0))
	abort();
}

////////////////////////////////////////////////////////////////////////////////

Locker::Locker(Mutex const &m) noexcept : _m{std::move(m)} {
    _m.lock();
}

Locker::~Locker() noexcept {
    _m.unlock();
}

////////////////////////////////////////////////////////////////////////////////
#endif
