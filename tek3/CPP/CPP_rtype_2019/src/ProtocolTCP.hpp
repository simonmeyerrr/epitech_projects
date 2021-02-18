#ifndef CPP_RTYPE_2019_PROTOCOLTCP_HPP
#define CPP_RTYPE_2019_PROTOCOLTCP_HPP

#include <vector>
#include <string>
#include <cstring>
#include "socket/ISocket.hpp"

#define MAGIC_NUMBER        0x45424142
#define PLAYERS_PER_ROOM    4
#define MAX_SIZE_STR        12

struct PlayerInfo {
    bool exist;
    int id;
    std::string username;
};

class ProtocolTCP {
public:
    using Action = enum {
        INVALID = -1,
        PING = 0,
        CONNECT,
        GET_ROOMS,
        CREATE_ROOM,
        JOIN_ROOM,
        LEAVE_ROOM,
        START_GAME,
        LAST_TYPE
    };

    using Request = struct my_request {
        unsigned int magic; // Magic number to verify if the packet is valid
        int action; // Id of the action requested
        unsigned int data_size; // Size of the data that will follow
    };

    using RequestConnectData = struct request_connect_data {
        char username[MAX_SIZE_STR];
    };

    using RequestCreateRoomData = struct request_create_room_data {
        char name[MAX_SIZE_STR];
    };

    using RequestJoinRoomData = struct request_join_room_data {
        int nb_room;
    };

    using DummyData = struct dummmy_data {

    };

    using Response = struct my_response {
        unsigned int magic; // Magic number to verify if the packet is valid
        bool status; // 0 = KO or 1 = OK, it respond to the request
        unsigned int data_size; // Size of the data that will follow
    };

    using Player = struct my_player {
        bool exist;
        char username[MAX_SIZE_STR];
        bool you;
    };
    using Players = Player[PLAYERS_PER_ROOM];

    using Room = struct my_room {
        int nb;
        char name[MAX_SIZE_STR];
        bool launched;
        Players players;
    };
    using Rooms = std::vector<Room>;

    using ResponseConnectData = struct response_connect_data {
        int id;
    };

    using ResponseCreateRoomData = struct response_create_room_data {
        my_socket::Port port;
    };

    using ResponseJoinRoomData = struct response_join_room_data {
        my_socket::Port port;
    };

    static std::string tabToStr(const char tab[MAX_SIZE_STR])
    {
        std::string str;

        for (int i = 0; i < MAX_SIZE_STR && tab && tab[i]; i++)
            str += tab[i];
        return str;
    }

    static void putStrIntoTab(char tab[MAX_SIZE_STR], const std::string &str)
    {
        for (unsigned int i = 0; i < MAX_SIZE_STR; i++) {
            if (i < str.size())
                tab[i] = str[i];
            else
                tab[i] = '\0';
        }
    }

    static my_socket::Buffer strToBuffer(const std::string &str)
    {
        return {str.begin(), str.end()};
    }

    static std::string bufferToStr(const my_socket::Buffer &data)
    {
        return {data.begin(), data.end()};
    }

    static bool isTabValid(const char tab[MAX_SIZE_STR])
    {
        if (!tab)
            return false;
        for (unsigned int i = 0; i < MAX_SIZE_STR && tab[i]; i++) {
            if (tab[i] < '0' || (tab[i] > '9' && tab[i] < 'A') || (tab[i] > 'Z' && tab[i] < 'a') || tab[i] > 'z')
                return false;
        }
        return true;
    }

    template <typename T>
    static std::pair<bool, T> getBody(const my_socket::Buffer &buffer)
    {
        T request;
        if (buffer.size() != sizeof(T)) {
            return {false, request};
        }
        std::memcpy(&request, buffer.data(), buffer.size());
        return {true, request};
    }

    template <typename T>
    static my_socket::Buffer setBody(const T &body)
    {
        my_socket::Buffer buffer(sizeof(T), 0);

        std::memcpy(buffer.data(), &body, sizeof(T));
        return buffer;
    }
};

#endif //CPP_RTYPE_2019_PROTOCOLTCP_HPP
