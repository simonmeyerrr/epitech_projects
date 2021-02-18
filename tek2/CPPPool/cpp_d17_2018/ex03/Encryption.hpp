/*
** EPITECH PROJECT, 2018
** cpp_d17_2018
** File description:
** Encryption.hpp
*/

#ifndef CPP_D17_2018_ENCRYPTION_HPP_
# define CPP_D17_2018_ENCRYPTION_HPP_

# include <algorithm>
# include <iostream>
# include <string>
# include "IEncryptionMethod.hpp"

class Encryption {
public:
    ~Encryption();
    Encryption(IEncryptionMethod &, void (IEncryptionMethod::*)(char));
    Encryption(const Encryption &);
    Encryption &operator=(const Encryption &);

    void operator()(char);

    static void encryptString(IEncryptionMethod &, const std::string &);
    static void decryptString(IEncryptionMethod &, const std::string &);

private:
    IEncryptionMethod &_method;
    void (IEncryptionMethod::*_func)(char);
};

#endif /* CPP_D17_2018_ENCRYPTION_HPP_ */
