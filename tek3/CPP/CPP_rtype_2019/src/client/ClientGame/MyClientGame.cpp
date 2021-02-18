#include "MyClientGame.hpp"
#include "../../socket/SocketError.hpp"

MyClientGame::MyClientGame(my_socket::IpV4 ip, my_socket::Port port, int userId)
    : AClientGame(), _ip(ip), _port(port), _userId(userId), _connected(false), _socket(nullptr), _infoPlayers(), _entities()
{
    for (int i = 0; i < PLAYERS_PER_ROOM; i++)
        _infoPlayers[i] = {false, false, 0, 0};
    _socket = std::make_unique<my_socket::SocketUDP>();
    _socket->connect(ip, port);
    try {
        sendPing({42});
        _connected = true;
    } catch (...) {
    }
}

void MyClientGame::sendPing(const ProtocolUDP::ActionPing &body)
{
    sendPacket(ProtocolUDP::ACTION_PING, body);
	std::cout << "sended ping " << body.pingId << std::endl;
}

void MyClientGame::sendMove(const ProtocolUDP::ActionMovePlayer &body)
{
    sendPacket(ProtocolUDP::ACTION_MOVE_PLAYER, body);
}

void MyClientGame::readPackets()
{
    try {
        for (int i = 0; i < 10; i++) {
            auto buffer = _socket->recv(2000);
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
            switch (header.action) {
                case ProtocolUDP::INFO_PING:
                    readPing(header, buffer);
                    break;
                case ProtocolUDP::INFO_PLAYERS:
                    readPlayers(header, buffer);
                    break;
                case ProtocolUDP::INFO_ENTITIES:
                    readEntities(header, buffer);
                    break;
                default:
                    std::cout << "Invalid info type" << std::endl;
            }
        }
    } catch (...) {}
}

template <typename T>
void MyClientGame::sendPacket(ProtocolUDP::Action action, const T &body)
{
    ProtocolUDP::Header header = {MAGIC_NUMBER, action, _userId, sizeof(body)};
    my_socket::Buffer buffer(sizeof(header) + sizeof(T), 0);

    std::memcpy(buffer.data(), &header, sizeof(header));
    std::memcpy(buffer.data() + sizeof(header), &body, sizeof(T));
    _socket->send(buffer);
}

void MyClientGame::readPing(const ProtocolUDP::Header &h, const my_socket::Buffer &buffer)
{
    if (buffer.size() != sizeof(h) + sizeof(ProtocolUDP::InfoPing)) {
        std::cout << "invalid size info ping" << std::endl;
        return;
    }
    ProtocolUDP::InfoPing body = {-1};
    std::memcpy(&body, buffer.data() + sizeof(h), sizeof(body));
	std::cout << "received ping " << body.pingId << std::endl;
}

void MyClientGame::readPlayers(const ProtocolUDP::Header &h, const my_socket::Buffer &buffer)
{
    if (buffer.size() != sizeof(h) + sizeof(ProtocolUDP::InfoPlayers)) {
        std::cout << "invalid size info players" << std::endl;
        return;
    }
    std::memcpy(&_infoPlayers, buffer.data() + sizeof(h), sizeof(ProtocolUDP::InfoPlayers));
}

void MyClientGame::readEntities(const ProtocolUDP::Header &h, const my_socket::Buffer &buffer)
{
    if ((buffer.size() - sizeof(h)) % sizeof(ProtocolUDP::Entity) != 0) {
        std::cout << "invalid size info entities" << std::endl;
        return;
    }
    ProtocolUDP::Entities entities((buffer.size() - sizeof(h)) / sizeof(ProtocolUDP::Entity));
    for (unsigned long i = 0; i < (buffer.size() - sizeof(h)) / sizeof(ProtocolUDP::Entity); i++) {
        std::memcpy(&entities[i], buffer.data() + sizeof(h) + (i * sizeof(ProtocolUDP::Entity)), sizeof(ProtocolUDP::Entity));
    }
    _entities = entities;
}