#include <iostream>
#include "Graphic/Graphic.hpp"
#include "../socket/socket_c/Includes.hpp"
#include "../LibLoader.hpp"

#include "../socket/socket_c/SocketUDP.hpp"
#include "../socket/Utils.hpp"

#define MAXLINE 256

int main(int ac, const char **av)
{
    int ret = 0;
#ifdef WIN32
    WSACleanup();
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 0), &WSAData);
#endif
	try {
	    /*
        int sockfd;
        char buffer[MAXLINE];
        char hello[] = "Hello from client";
        struct sockaddr_in     servaddr;

        // Creating socket file descriptor
        if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }

        memset(&servaddr, 0, sizeof(servaddr));

        // Filling server information
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(8090);
        servaddr.sin_addr.s_addr = my_socket::Utils::strToIp("127.0.0.1");

        int n;
        socklen_t len;

        sendto(sockfd, (const char *)hello, strlen(hello),
               0, (const struct sockaddr *) &servaddr,
               sizeof(servaddr));
        printf("Hello message sent.\n");
        std::cout << servaddr.sin_port << std::endl;

        n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                     0, (struct sockaddr *) &servaddr,
                     &len);
        buffer[n] = '\0';
        printf("Server : %s\n", buffer);

        close(sockfd);
*/
	    /*
	    my_socket::SocketUDP socket;
	    socket.connect(my_socket::Utils::strToIp("10.14.58.173"), 8080);
	    std::cout << "send" << std::endl;
	    socket.send(ProtocolTCP::strToBuffer("Hello toi !"));
        my_socket::Utils::sleep(1000);
        std::cout << "send" << std::endl;
        socket.send(ProtocolTCP::strToBuffer("Hello toi !"));
        my_socket::Utils::sleep(1000);
        std::cout << "send" << std::endl;
        socket.send(ProtocolTCP::strToBuffer("Hello toi !"));
        my_socket::Utils::sleep(1000);
        std::cout << "send" << std::endl;
        socket.send(ProtocolTCP::strToBuffer("Hello toi !"));
        my_socket::Utils::sleep(1000);
        */
        Graphic().run();
	} catch (...) {
	    std::cerr << "Unknown exception caught" << std::endl;
	    ret = 84;
	}
#ifdef WIN32
    WSACleanup();
#endif
    return (ret);
}
