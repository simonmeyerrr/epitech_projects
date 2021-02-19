#ifndef INDEXVARIA_HPP_
#define INDEXVARIA_HPP_

template<std::size_t W, typename T> struct Dexed {
    using type = T;
};

template<typename W, typename ...T> struct Dexer;

template<std::size_t ...W, typename ...T> struct Dexer<std::index_sequence<W...>, T...> : Dexed<W, T>...{
};

template<std::size_t W, typename T> static Dexed<W, T> Slct(Dexed<W, T>);

template<std::size_t W, typename ...T> using IndexVaria = typename decltype(Slct<W>(Dexer<std::index_sequence_for<T...>, T...>{}))::type;

#endif
