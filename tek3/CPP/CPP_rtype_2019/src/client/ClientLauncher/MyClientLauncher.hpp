#ifndef CPP_RTYPE_2019_MYCLIENTLAUNCHER_HPP
#define CPP_RTYPE_2019_MYCLIENTLAUNCHER_HPP

#include <mutex>
#include <thread>
#include <atomic>
#include "AClientLauncher.hpp"
#include "../../socket/ISocket.hpp"

class MyClientLauncher : public AClientLauncher {
public:
    ~MyClientLauncher() override;
    explicit MyClientLauncher();

    my_socket::IpV4 getIp() const override;
    void connect(const std::string &username,  my_socket::IpV4 ip, my_socket::Port port) override;
    void disconnect() override;
    void createRoom(const std::string &name) override;
    void joinRoom(int nbRoom) override;
    void leaveRoom() override;
    void startGame() override;

private:
    void loopThread();
    void fetchRooms();

    template <typename T>
    std::pair<bool, my_socket::Buffer > makeRequest(ProtocolTCP::Action, const T &body);
    std::pair<bool, my_socket::Buffer > getResponse();

    my_socket::ISocketPtr _socket;
    std::mutex _mutex;
    std::atomic<bool> _threaded;
    std::thread _thread;
};


#endif /* CPP_RTYPE_2019_MYCLIENTLAUNCHER_HPP */
