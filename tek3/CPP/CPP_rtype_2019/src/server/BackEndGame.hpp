#ifndef CPP_RTYPE_2019_BACKENDGAME_HPP
#define CPP_RTYPE_2019_BACKENDGAME_HPP

#include <mutex>
#include <thread>
#include "../socket/AServerUDP.hpp"
#include "../ProtocolUDP.hpp"
#include "core/Core.hpp"

class BackEndGame : public my_socket::IBackEndUDP {
public:
    ~BackEndGame() override;
    BackEndGame();

    void communicate(my_socket::ISocketPtr socket) override;
    void updateRoom(int nb, const PlayerInfo &player);
    bool start();

private:
    int getUserNumber(int userId);

    void actionPing(my_socket::ISocketPtr &socket, int nb, const ProtocolUDP::Header &header, const my_socket::Buffer &buffer);
    void actionMove(my_socket::ISocketPtr &socket, int nb, const ProtocolUDP::Header &header, const my_socket::Buffer &buffer);
    void sendEveryData(my_socket::ISocketPtr &socket);

    template <typename T>
    void sendPacket(my_socket::ISocketPtr &socket, ProtocolUDP::Info info, const T &body);
    void sendPacket(my_socket::ISocketPtr &socket, ProtocolUDP::Info info, const my_socket::Buffer &body);

    std::mutex _mutex;
    std::atomic<bool> _started;
    PlayerInfo _players[PLAYERS_PER_ROOM];
    std::unique_ptr<Core> _engine;
    std::thread _thread;
};

#endif /* CPP_RTYPE_2019_BACKENDGAME_HPP */
