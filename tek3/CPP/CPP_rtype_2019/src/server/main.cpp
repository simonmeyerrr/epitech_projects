#include <iostream>
#include <thread>
#include "BackEndLauncher.hpp"
#include "../socket/socket_c/ServerTCP.hpp"
#include "../socket/Utils.hpp"
#include "../LibLoader.hpp"

int main(int ac, const char **av)
{
    int ret = 0;
#ifdef WIN32
    WSACleanup();
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 0), &WSAData);
#endif
    try {
        my_socket::Port port = 8080;

        if (ac == 2)
            port = std::stoi(av[1]);

        std::unique_ptr<BackEndLauncher> backend(new BackEndLauncher(port));
        my_socket::IServerPtr server(new my_socket::ServerTCP(*backend, port, 5));

        std::thread thread(&my_socket::IServer::start, server.get());

        while (!server->hasError() && !server->isWorking());
        if (server->hasError()) {
            std::cout << "Error while starting server" << std::endl;
            server->stopServer();
            thread.join();
            return 84;
        } else {
            std::cout << "Server started on " << my_socket::Utils::ipToStr(my_socket::Utils::getMyIp()) << ":" << server->getPort() << std::endl;
            std::cout << "Type text and press enter to stop server" << std::endl;
        }
        std::string str;
        std::cin >> str;
        std::cout << "Stopping server..." << std::endl;
        server->stopServer();
        thread.join();

    } catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
        ret = 84;
    }
#ifdef WIN32
    WSACleanup();
#endif
    return (ret);
}