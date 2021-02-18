/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** MsgQClient.cpp
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "MsgQClient.hpp"
#include <errno.h>
#include <string.h>

MsgQClient::~MsgQClient()
{
    //msgctl(_msgid2, IPC_RMID, nullptr);
}

MsgQClient::MsgQClient(int encriptionKey)
    : _encriptionKey(encriptionKey), _key1(), _msgid1(), _key2(), _msgid2()
{
    _key1 = ftok("progfile", _encriptionKey);
    if (_key1 == -1) {
        std::cout << strerror(errno) << std::endl;
        return; // exeption
    }
    _msgid1 = msgget(_key1, 0666 | IPC_CREAT);
    if (_msgid1 == -1) {
        std::cout << strerror(errno) << std::endl;
        return; // exeption
    }
    _key2 = ftok("progfile", _encriptionKey + 2);
    if (_key2 == -1) {
        std::cout << strerror(errno) << std::endl;
        return; // exeption
    }
    _msgid2 = msgget(_key2, 0666 | IPC_CREAT);
    if (_msgid2 == -1) {
        std::cout << strerror(errno) << std::endl;
        return; // exeption
    }
}

unsigned int MsgQClient::sendMessage(unsigned int message)
{
    std::cout << "client " << _encriptionKey << " send " << message <<
    std::endl;
    struct mesg_buffer msg = {1, message};
    if (msgsnd(_msgid1, &msg, sizeof(msg), 0) == -1)
        std::cerr << strerror(errno) << std::endl;
    msg.mesg = 0;
    if (msgrcv(_msgid2, &msg, sizeof(msg), 0, 0) == -1)
        std::cerr << strerror(errno) << std::endl;
    std::cout << "client " << _encriptionKey + 2 << " has res " << msg.mesg <<
    std::endl;
    return msg.mesg;
}

void MsgQClient::sendUniqueMessage(unsigned int message)
{
    std::cout << "client " << _encriptionKey << " send unique " << message <<
        std::endl;
    struct mesg_buffer msg = {1, message};
    if (msgsnd(_msgid1, &msg, sizeof(msg), 0) == -1)
        std::cerr << strerror(errno) << std::endl;
}

int MsgQClient::getEncriptionKey() const
{
    return _encriptionKey;
}