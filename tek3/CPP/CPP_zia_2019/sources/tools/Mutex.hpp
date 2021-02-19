#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <functional>
#include <cstddef>

////////////////////////////////////////////////////////////////////////////////
#ifdef WIN32

#include <mutex>
using Mutex = std::mutex;
using Locker = std::lock_guard<std::mutex>;

#else

class Mutex {
public:
    void lock() const noexcept;
    void unlock() const noexcept;
private:
    static inline std::size_t cmpxchg(std::size_t *v, std::size_t o, std::size_t n) noexcept {
#ifndef __X86_64_CPU__
	return __sync_val_compare_and_swap(v, o, n) == o;
#else
	unsigned char s; __asm__ __volatile__ ("lock cmpxchgq %3, %1\nsete %0\n" : "=q"(s), "+m"(*v), "+a"(o) : "r"(n)); return s;
#endif
    }
    mutable std::size_t _owner = 0;
};

////////////////////////////////////////////////////////////////////////////////
class Locker {
public:
    explicit Locker(Mutex const &) noexcept;
    ~Locker() noexcept;
private:
    Mutex const &_m;
};
#endif
////////////////////////////////////////////////////////////////////////////////

#endif
