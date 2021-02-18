/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** MsgQServer.cpp
*/

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "MsgQServer.hpp"

MsgQServer::~MsgQServer()
{
    msgctl(_msgid1, IPC_RMID, nullptr);
    msgctl(_msgid2, IPC_RMID, nullptr);
}

MsgQServer::MsgQServer(const int encriptionKey)
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

unsigned int MsgQServer::getMessage()
{
    struct mesg_buffer msg = {1, 0};
    int res = msgrcv(_msgid1, &msg, sizeof(msg), 0, IPC_NOWAIT);

    if (res == -1)
        return (0);
    std::cout << "server " << _encriptionKey << " get " << msg.mesg <<
        std::endl;
    return msg.mesg;
}

void MsgQServer::respond(unsigned int message)
{
    std::cout << "server " << _encriptionKey + 2 << " respond " << message <<
        std::endl;
    struct mesg_buffer msg = {1, message};
    msgsnd(_msgid2, &msg, sizeof(msg), 0);
}

int MsgQServer::getEncriptionKey() const
{
    return _encriptionKey;
}