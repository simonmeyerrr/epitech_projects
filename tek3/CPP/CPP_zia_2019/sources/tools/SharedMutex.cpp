#include "SharedMutex.hpp"

////////////////////////////////////////////////////////////////////////////////
#ifndef WIN32
void SharedMutex::wlock() const noexcept {
    _m.lock();
    while (State::free != _state) {
	_m.unlock();
	_m.lock();
    }
    _state = State::write;
    _m.unlock();
    _owners.emplace_back(pthread_self());
}

void SharedMutex::rlock() const noexcept {
    _m.lock();
    while (State::free != _state && State::read != _state) {
	_m.unlock();
	_m.lock();
    }
    _state = State::read;
    _owners.emplace_back(pthread_self());
    _m.unlock();
}

void SharedMutex::unlock() const noexcept {
    Locker lock{_m};
    if (State::read == _state) {
	std::deque<std::size_t>::iterator attempt = std::find(_owners.begin(), _owners.end(), pthread_self());
	if (_owners.end() == attempt)
	    abort();
	_owners.erase(attempt);
	if (!_owners.size())
	    _state = State::free;
    } else if (State::write == _state) {
	if (1 != _owners.size() || pthread_self() != _owners.back())
	    abort();
	_owners.pop_back();
	_state = State::free;
    } else
	abort();
}

////////////////////////////////////////////////////////////////////////////////

WLocker::WLocker(SharedMutex const &m) noexcept : _m{std::move(m)} {
    _m.wlock();
}

WLocker::~WLocker() noexcept {
    _m.unlock();
}

////////////////////////////////////////////////////////////////////////////////

RLocker::RLocker(SharedMutex const &m) noexcept : _m{std::move(m)} {
	_m.rlock();
    }

RLocker::~RLocker() noexcept {
    _m.unlock();
}
#endif
////////////////////////////////////////////////////////////////////////////////
