/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Toy.hpp
*/

#ifndef CPP_D13_2018_TOY_HPP_
# define CPP_D13_2018_TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    Toy();
    Toy(ToyType, const std::string &, const std::string &);
    Toy(const Toy &other);
    ~Toy();

    ToyType getType() const;

    std::string getName() const;
    void setName(const std::string &name);

    bool setAscii(const std::string &file);
    std::string getAscii() const;

    virtual bool speak(const std::string &);
    virtual bool speak_es(const std::string &);

    Toy &operator=(const Toy &other);
    Toy &operator<<(const std::string &other);

    class Error {
    public:
        enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        };

        Error() : type(UNKNOWN) {}
        ~Error() = default;

        std::string what() const;
        std::string where() const;
        ErrorType type;
    };

    Error getLastError() const;

protected:
    ToyType _type;
    std::string _name;
    Picture _picture;
    Error _lastError;
};

std::ostream &operator<<(std::ostream &stream, const Toy &toy);

#endif /* CPP_D13_2018_TOY_HPP_ */
