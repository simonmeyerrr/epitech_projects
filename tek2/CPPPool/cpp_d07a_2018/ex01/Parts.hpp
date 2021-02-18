/*
** EPITECH PROJECT, 2018
** cpp_d07a_2018
** File description:
** Parts.hpp
*/

#ifndef CPP_D07A_2018_PARTS_HPP_
# define CPP_D07A_2018_PARTS_HPP_

# include <string>

class Arms {
public:
    // Ctor and Dtor
    Arms(std::string const & = "A-01", bool = true);
    ~Arms();

    // Member functions
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;

private:
    // Properties
    std::string _serial;
    bool _functional;
};

class Legs {
public:
    // Ctor and Dtor
    Legs(std::string const & = "L-01", bool = true);
    ~Legs();

    // Member functions
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;

private:
    // Properties
    std::string _serial;
    bool _functional;
};

class Head {
public:
    // Ctor and Dtor
    Head(std::string const & = "H-01", bool = true);
    ~Head();

    // Member functions
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;

private:
    // Properties
    std::string _serial;
    bool _functional;
};

#endif /* CPP_D07A_2018_PARTS_HPP_ */
