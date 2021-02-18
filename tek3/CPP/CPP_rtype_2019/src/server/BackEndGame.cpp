#include <iostream>
#include "BackEndGame.hpp"

BackEndGame::~BackEndGame()
{
    if (_engine) {
        _engine->stop();
        _thread.join();
        _engine = nullptr;
    }
}

BackEndGame::BackEndGame()
    : _mutex(), _started(false), _players(), _engine(nullptr), _thread()
{
}

void BackEndGame::communicate(my_socket::ISocketPtr socket)
{
    try {
        auto buffer = socket->recv(2000);
        if (!_started)
            return;
        ProtocolUDP::Header header = {0, 0, 0, 0};
        if (buffer.size() < sizeof(header)) {
            std::cout << "too small packet" << std::endl;
            return;
        }
        std::memcpy(&header, buffer.data(), sizeof(header));
        if (header.magic != MAGIC_NUMBER) {
            std::cout << "invalid magic number" << std::endl;
            return;
        } else if (header.data_size != buffer.size() - sizeof(header)) {
            std::cout << "not matching body size" << std::endl;
            return;
        }
        int nbUser = getUserNumber(header.user_id);
        if (nbUser < 0) {
            std::cout << "unauthorize user" << std::endl;
            return;
        }
        switch (header.action) {
            case ProtocolUDP::ACTION_PING:
                actionPing(socket, nbUser, header, buffer);
                break;
            case ProtocolUDP::ACTION_MOVE_PLAYER:
                actionMove(socket, nbUser, header, buffer);
                break;
            default:
                std::cout << "Invalid action type" << std::endl;
        }
    } catch (...) {
        std::cout << "error socket" << std::endl;
    }
}

void BackEndGame::updateRoom(int nb, const PlayerInfo &player)
{
    _mutex.lock();
    std::cout << "update room backend" << std::endl;
    _players[nb] = player;
    _mutex.unlock();
    if (!player.exist && _engine)
        _engine->removePlayer(nb);
}

bool BackEndGame::start()
{
    if (_started)
        return false;
    _started = true;
    _engine = std::make_unique<Core>(_players);
    _thread = std::thread(&Core::gameLoop, _engine.get());
    return true;
}

int BackEndGame::getUserNumber(int userId)
{
    int nb = -1;
    _mutex.lock();
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        if (_players[i].exist && _players[i].id == userId) {
            nb = i;
            break;
        }
    }
    _mutex.unlock();
    return nb;
}

void BackEndGame::actionPing(my_socket::ISocketPtr &socket, int nb, const ProtocolUDP::Header &h, const my_socket::Buffer &buffer)
{
    if (buffer.size() != sizeof(h) + sizeof(ProtocolUDP::ActionPing)) {
        std::cout << "invalid size action ping" << std::endl;
        return;
    }
    ProtocolUDP::ActionPing body = {-1};
    std::memcpy(&body, buffer.data() + sizeof(h), sizeof(body));
    ProtocolUDP::InfoPing bodyRes = {body.pingId};
    sendPacket(socket, ProtocolUDP::INFO_PING, bodyRes);
}

void BackEndGame::actionMove(my_socket::ISocketPtr &socket, int nb, const ProtocolUDP::Header &h, const my_socket::Buffer &buffer)
{
    if (buffer.size() != sizeof(h) + sizeof(ProtocolUDP::ActionMovePlayer)) {
        std::cout << "invalid size action move" << std::endl;
        return;
    }
    ProtocolUDP::ActionMovePlayer body = {false, false, false, false};
    std::memcpy(&body, buffer.data() + sizeof(h), sizeof(body));
    _engine->handleMovement(nb, body);
    sendEveryData(socket);
}

void BackEndGame::sendEveryData(my_socket::ISocketPtr &socket)
{
    auto players = _engine->getPlayers();
    ProtocolUDP::InfoPlayers infoPlayers = {};
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        if (std::size_t(i) < players.size())
            infoPlayers[i] = players[i];
        else
            infoPlayers[i] = {false, false, 0, 0};
    }
    sendPacket(socket, ProtocolUDP::INFO_PLAYERS, infoPlayers);
    auto entities = _engine->getEntities();
    my_socket::Buffer entitiesBuffer(entities.size() * sizeof(ProtocolUDP::Entity), 0);
    std::memcpy(entitiesBuffer.data(), entities.data(), entities.size() * sizeof(ProtocolUDP::Entity));
    sendPacket(socket, ProtocolUDP::INFO_ENTITIES, entitiesBuffer);
}


template <typename T>
void BackEndGame::sendPacket(my_socket::ISocketPtr &socket, ProtocolUDP::Info info, const T &body)
{
    ProtocolUDP::Header header = {MAGIC_NUMBER, info, -1, sizeof(body)};
    my_socket::Buffer buffer(sizeof(header) + sizeof(T), 0);

    std::memcpy(buffer.data(), &header, sizeof(header));
    std::memcpy(buffer.data() + sizeof(header), &body, sizeof(T));
    socket->send(buffer);
}

void BackEndGame::sendPacket(my_socket::ISocketPtr &socket, ProtocolUDP::Info info, const my_socket::Buffer &body)
{
    ProtocolUDP::Header header = {MAGIC_NUMBER, info, -1, static_cast<unsigned int>(body.size())};
    my_socket::Buffer buffer(sizeof(header) + body.size(), 0);

    std::memcpy(buffer.data(), &header, sizeof(header));
    std::memcpy(buffer.data() + sizeof(header), body.data(), body.size());
    socket->send(buffer);
}