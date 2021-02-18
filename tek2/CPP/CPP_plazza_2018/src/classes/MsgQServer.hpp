/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** MsgQServer.hpp
*/

#include <iostream>

class MsgQServer {
public:
    ~MsgQServer();
    MsgQServer(int encriptionKey);

    unsigned int getMessage();
    void respond(unsigned int);
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
