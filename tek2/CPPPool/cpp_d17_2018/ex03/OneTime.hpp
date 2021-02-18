/*
** EPITECH PROJECT, 2018
** cpp_d17_2018
** File description:
** OneTime.hpp
*/

#ifndef CPP_D17_2018_ONETIME_HPP_
# define CPP_D17_2018_ONETIME_HPP_

# include <iostream>
# include <string>
# include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod {
public:
    ~OneTime();
    OneTime(const std::string &key);
    OneTime(const OneTime &);
    OneTime &operator=(const OneTime &);

    void encryptChar(char plainchar);
    void decryptChar(char cipherchar);
    void reset();

private:
    std::string _key;
    unsigned int _offset;
    unsigned int _max;
};

#endif /* CPP_D17_2018_ONETIME_HPP_ */
