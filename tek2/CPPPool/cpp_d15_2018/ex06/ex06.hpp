/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex06.hpp
*/

#ifndef CPP_D15_2018_EX06_HPP_
# define CPP_D15_2018_EX06_HPP_

# include <sstream>
# include <string>

template<typename T>
std::string getString(T elem)
{
    (void) elem;
    return (std::string("[???]"));
}
template<>
std::string getString(int nb)
{
    std::stringstream s;
    s << nb;
    return (std::string("[int:") + s.str() + "]");
}

template<>
std::string getString(float nb)
{
    std::stringstream s;
    s << nb;
    return ("[float:" + s.str() + "f]");
}

template<>
std::string getString(std::string str)
{
    return (std::string("[string:\"") + str + "\"]");
}

template<typename T, typename U = T>
class Tuple {
public:
    std::string toString() const
    {
        return (std::string("[TUPLE ") +
            getString(a) + " " + getString(b) + "]");
    }

    T a;
    U b;
};

#endif /* CPP_D15_2018_EX06_HPP_ */
