#ifndef VARIANT_HPP_
#define VARIANT_HPP_

#include <variant>

#include "IndexVaria.hpp"

template<typename T> struct Literal {
};

template<typename W, typename ...T> struct IndexByType;

template<typename W, typename ...T> struct IndexByType<W, std::variant<T...>> final : public std::integral_constant<std::size_t, std::variant<Literal<T>...>{Literal<W>()}.index()> {
};

template<typename ...T> struct Variant final : public std::variant<T...> {
    using std::variant<T...>::variant;

    std::variant<T...> *operator()() {
	return dynamic_cast<std::variant<T...> *>(this);
    }
    
    template<typename W> bool is() const noexcept {
	return IndexByType<W, std::variant<T...>>{} == std::variant<T...>::index();
    }

    template<std::size_t W> bool is() const noexcept {
	return W == std::variant<T...>::index();
    }

    template<std::size_t W> IndexVaria<W, T...> &as() {
	return std::get<W>(*this);
    }

    template<std::size_t W> IndexVaria<W, T...> const &as() const {
	return std::get<W>(*this);
    }

    template<typename W> W &as() {
	return std::get<W>(*this);
    }

    template<typename W> W const &as() const {
	return std::get<W>(*this);
    }
};

#endif
