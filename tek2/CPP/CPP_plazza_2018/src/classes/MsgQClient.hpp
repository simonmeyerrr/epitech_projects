/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** MsgQClient.hpp
*/

#ifndef CPP_PLAZZA_2018_MSGQCLIENT_HPP
#define CPP_PLAZZA_2018_MSGQCLIENT_HPP

#include <iostream>

class MsgQClient {
public:
    ~MsgQClient();
    MsgQClient(int encriptionKey);

    unsigned int sendMessage(unsigned int);
    void sendUniqueMessage(unsigned int);
    int getEncriptionKey() const;

private:
    const int _encriptionKey;
    key_t _key1;
    int _msgid1;
    key_t _key2;
    int _msgid2;

    struct mesg_buffer {
        short mesg_type;
        unsigned int mesg;
    };
};

#endif /* CPP_PLAZZA_2018_MSGQCLIENT_HPP */
