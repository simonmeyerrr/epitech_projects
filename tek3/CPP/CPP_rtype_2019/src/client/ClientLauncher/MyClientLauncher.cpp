#include <iostream>
#include <cstring>
#include "MyClientLauncher.hpp"
#include "../../socket/socket_c/SocketTCP.hpp"
#include "../../socket/Utils.hpp"

MyClientLauncher::~MyClientLauncher()
{
    if (_connected)
        disconnect();
}

MyClientLauncher::MyClientLauncher()
    : AClientLauncher(), _socket(nullptr), _mutex(), _threaded(false), _thread()
{
}

my_socket::IpV4 MyClientLauncher::getIp() const
{
    return _socket->getTargetIp();
}

void MyClientLauncher::connect(const std::string &username,  my_socket::IpV4 ip, my_socket::Port port)
{
    if (_connected || _connecting)
        return;
    _mutex.lock();
    _connecting = true;
    try {
        _socket = std::make_unique<my_socket::SocketTCP>();
        _socket->connect(ip, port);

        ProtocolTCP::RequestConnectData reqBody = {};
        ProtocolTCP::putStrIntoTab(reqBody.username, username);
        auto res = makeRequest(ProtocolTCP::CONNECT, reqBody);

        auto resBody = ProtocolTCP::getBody<ProtocolTCP::ResponseConnectData>(res.second);
        if (!resBody.first) {
            std::cout << ProtocolTCP::bufferToStr(res.second) << std::endl;
            _socket = nullptr;
        } else {
            _myId = resBody.second.id;
            _connected = true;
        }
        _connecting = false;
        _thread = std::thread(&MyClientLauncher::loopThread, this);
        _threaded = true;
        _mutex.unlock();
    } catch (...) {
        _mutex.unlock();
        disconnect();
    }
}

void MyClientLauncher::disconnect()
{
    _mutex.lock();
    _socket = nullptr;
    _connected = false;
    _connecting = false;
    _inRoom = false;
    _master = false;
    _inGame = false;
    _rooms.clear();
    _myId = -1;
    _port = 0;
    _fetchError = false;
    _mutex.unlock();
    if (_threaded)
        _thread.join();
    _threaded = false;
}

void MyClientLauncher::createRoom(const std::string &name)
{
    if (!_connected || !_socket)
        return;
    _mutex.lock();

    try {
        ProtocolTCP::RequestCreateRoomData reqBody = {{}};
        ProtocolTCP::putStrIntoTab(reqBody.name, name);
        auto res = makeRequest(ProtocolTCP::CREATE_ROOM, reqBody);

        auto resBody = ProtocolTCP::getBody<ProtocolTCP::ResponseCreateRoomData >(res.second);
        if (!resBody.first) {
            std::cout << ProtocolTCP::bufferToStr(res.second) << std::endl;
        } else {
            _inRoom = true;
            _inGame = false;
            _master = true;
            _port = resBody.second.port;
        }
        _mutex.unlock();
    } catch (...) {
        _mutex.unlock();
        disconnect();
    }
}

void MyClientLauncher::joinRoom(int nbRoom)
{
    if (!_connected || !_socket)
        return;
    _mutex.lock();

    try {
        ProtocolTCP::RequestJoinRoomData reqBody = {};
        reqBody.nb_room = nbRoom;
        auto res = makeRequest(ProtocolTCP::JOIN_ROOM, reqBody);

        auto resBody = ProtocolTCP::getBody<ProtocolTCP::ResponseJoinRoomData>(res.second);
        if (!resBody.first) {
            std::cout << ProtocolTCP::bufferToStr(res.second) << std::endl;
        } else {
            _inRoom = true;
            _inGame = false;
            _master = false;
            _port = resBody.second.port;
        }
        _mutex.unlock();
    } catch (...) {
        _mutex.unlock();
        disconnect();
    }
}

void MyClientLauncher::leaveRoom()
{
    if (!_connected || !_socket)
        return;
    _mutex.lock();

    try {
        ProtocolTCP::DummyData reqBody = {};
        auto resBody = makeRequest(ProtocolTCP::LEAVE_ROOM, reqBody);

        if (!resBody.first)
            std::cout << ProtocolTCP::bufferToStr(resBody.second) << std::endl;
        else {
            _inRoom = false;
            _inGame = false;
            _master = false;
            _port = -1;
        }
        _mutex.unlock();
    } catch (...) {
        _mutex.unlock();
        disconnect();
    }
}

void MyClientLauncher::startGame()
{
    if (!_connected)
        return;
    _mutex.lock();

    try {
        ProtocolTCP::DummyData reqBody = {};
        auto resBody = makeRequest(ProtocolTCP::START_GAME, reqBody);

        if (!resBody.first)
            std::cout << ProtocolTCP::bufferToStr(resBody.second) << std::endl;
        else
            _inGame = true;
        _mutex.unlock();
    } catch (...) {
        _mutex.unlock();
        disconnect();
    }
}

template <typename T>
std::pair<bool, my_socket::Buffer > MyClientLauncher::makeRequest(ProtocolTCP::Action action, const T &body)
{
    if (!_socket) {
        return {false, {0}};
    }
    ProtocolTCP::Request header = {MAGIC_NUMBER, action, sizeof(T)};
    my_socket::Buffer buffer(sizeof(ProtocolTCP::Request) + sizeof(T), 0);
    std::memcpy(buffer.data(), &header, sizeof(ProtocolTCP::Request));
    std::memcpy(buffer.data() + sizeof(ProtocolTCP::Request), &body, sizeof(T));
    _socket->send(buffer);
    return getResponse();
}

std::pair<bool, my_socket::Buffer > MyClientLauncher::getResponse()
{
    ProtocolTCP::Response res = {0, false, 0};
    my_socket::Buffer data(0, 0);
    auto header = _socket->recv(sizeof(ProtocolTCP::Response));

    if (header.size() != sizeof(ProtocolTCP::Response))
        return {false, data};
    std::memcpy(&res, header.data(), sizeof(ProtocolTCP::Response));

    if (res.magic != MAGIC_NUMBER)
        return {false, data};

    if (res.data_size != 0) {
        data = _socket->recv(res.data_size);
        if (data.size() != res.data_size) {
            return {false, data};
        }
    }
    return {res.status, data};
}

void MyClientLauncher::loopThread()
{
    _fetchError = false;
    while (_connected && !_fetchError) {
        my_socket::Utils::sleep(1000);
        fetchRooms();
    }
}

void MyClientLauncher::fetchRooms() {
    if (!_connected || !_socket)
        return;
    _mutex.lock();

    try {
        ProtocolTCP::DummyData reqBody = {};
        auto res = makeRequest(ProtocolTCP::GET_ROOMS, reqBody);

        if (!res.first) {
            std::cout << ProtocolTCP::bufferToStr(res.second) << std::endl;
        } else if (res.second.size() % sizeof(ProtocolTCP::Room) == 0) {
            ProtocolTCP::Rooms rooms(res.second.size() / sizeof(ProtocolTCP::Room));
            for (unsigned long i = 0; i < res.second.size() / sizeof(ProtocolTCP::Room); i++) {
                ProtocolTCP::Room room;
                std::memcpy(&room, res.second.data() + (i * sizeof(ProtocolTCP::Room)), sizeof(ProtocolTCP::Room));
                rooms[i] = room;
            }
            _rooms = rooms;
        }
        _mutex.unlock();
        bool inRoom = false;
        bool inGame = false;
        bool isMaster = false;
        for (const auto &room: _rooms) {
            for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
                if (room.players[i].you) {
                    inRoom = true;
                    inGame = room.launched;
                    isMaster = i == 0;
                }
            }
        }
        _inRoom = inRoom;
        _inGame = inGame;
        _master = isMaster;
    } catch (...) {
        _fetchError = true;
        _mutex.unlock();
    }
}
