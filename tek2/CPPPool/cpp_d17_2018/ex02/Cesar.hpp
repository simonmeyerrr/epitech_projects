/*
** EPITECH PROJECT, 2018
** cpp_d17_2018
** File description:
** Cesar.hpp
*/

#ifndef CPP_D17_2018_CESAR_HPP_
# define CPP_D17_2018_CESAR_HPP_

# include <iostream>
# include <string>
# include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
public:
    ~Cesar();
    Cesar();
    Cesar(const Cesar &);
    Cesar &operator=(const Cesar &);

    void encryptChar(char plainchar);
    void decryptChar(char cipherchar);
    void reset();

private:
    int _decalage;
};

#endif /* CPP_D17_2018_CESAR_HPP_ */
