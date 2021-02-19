#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <thread>
#include <future>
#include <memory>
#include <exception>

////////////////////////////////////////////////////////////////////////////////

template<typename R = void, bool B = true> class Thread : public std::thread {
public:
    Thread() noexcept : std::thread::thread(), p{}, f{}, r{}, b{!B} {
    }

    Thread(std::thread &&t) noexcept : std::thread::thread{std::move(t)}, b{!B} {
    }

    template<typename T = R, typename F, typename ...A, class = typename std::enable_if<!std::is_same<void, T>::value>::type> explicit Thread(F &&f, A &&...a) : std::thread::thread{}, p{}, f{p.get_future()}, r{}, b{!B} {
	*this = std::move(std::thread{f, std::forward<A>(a)..., std::move(p)});
    }

    template<typename T = R, class = typename std::enable_if<std::is_same<void, T>::value>::type, typename F, typename ...A> explicit Thread(F &&f, A &&...a) : std::thread::thread{f, std::forward<A>(a)...}, p{}, f{}, r{}, b{false} {
    }

    Thread(const thread &) noexcept = delete;

    ~Thread() noexcept {
    }

    using std::thread::thread;

    template<typename T = R> typename std::enable_if<!std::is_same<void, T>::value && !B && std::is_copy_constructible<R>::value, T>::type get() const {
	return *r;
    }

    template<typename T = R> typename std::enable_if<!std::is_same<void, T>::value && B && std::is_copy_constructible<R>::value, T>::type get() const {
	if (!b)
	    throw "Thread :: get :: Did not end and get was called with safety on";
	return *r;
    }

    template<typename T = R> typename std::enable_if<!std::is_same<void, T>::value && !B && !std::is_copy_constructible<R>::value, T>::type get() const {
	return std::move(*r);
    }

    template<typename T = R> typename std::enable_if<!std::is_same<void, T>::value && B && !std::is_copy_constructible<R>::value, T>::type get() const {
	if (!b)
	    throw "Thread :: get :: Did not end and get was called with safety on";
	return std::move(*r);
    }
	
    template<typename T = R> typename std::enable_if<std::is_same<void, T>::value, void>::type get() const noexcept = delete;

    template<typename T = R> typename std::enable_if<!std::is_same<void, T>::value && !B>::type join() {
	std::thread::join();
	r = std::make_shared<R>(f.get());
    }

    template<typename T = R> typename std::enable_if<!std::is_same<void, T>::value && B>::type join() {
	std::thread::join();
	r = std::make_shared<R>(f.get());
	b = true;
    }

    template<typename T = R> typename std::enable_if<std::is_same<void, T>::value>::type join() {
	std::thread::join();
    }

    std::future<R> &&detach() {
	std::thread::detach();
	return std::move(f);
    }

    Thread &operator=(std::thread &&t) noexcept {
	std::thread::operator=(std::move(t));
	return *this;
    }

    Thread &operator=(Thread &t) noexcept {
	return *this = std::forward<std::thread &&>(t);
    }

private:	
    std::promise<R> p;
    std::future<R> f;
    std::shared_ptr<R> r;
    bool b;
};

////////////////////////////////////////////////////////////////////////////////

#endif
