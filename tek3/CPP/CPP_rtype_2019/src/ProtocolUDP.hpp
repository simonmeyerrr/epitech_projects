#ifndef CPP_RTYPE_2019_PROTOCOLUDP_HPP
#define CPP_RTYPE_2019_PROTOCOLUDP_HPP

#include <vector>
#include <string>
#include <cstring>
#include "socket/ISocket.hpp"
#include "ProtocolTCP.hpp"

class ProtocolUDP {
public:
    struct Header {
        unsigned int magic; // Magic number to verify if the packet is valid
        int action; // Id of the action or info requested
        int user_id;
        unsigned int data_size; // Size of the data that will follow
    };

    using Action = enum {
        ACTION_INVALID = -1,
        ACTION_PING = 0,
        ACTION_MOVE_PLAYER = 1
    };

    using EntityType = enum {
        PLAYER1,
        PLAYER2,
        PLAYER3,
        PLAYER4,
        MONSTER,
        ROCKET,
        MONSTER2
    };

   struct ActionPing {
        int pingId;
    };

    struct ActionMovePlayer {
        bool up;
        bool down;
        bool right;
        bool left;
    };

    using Info = enum {
        INFO_INVALID = -1,
        INFO_PING = 0,
        INFO_PLAYERS = 1,
        INFO_ENTITIES
    };

    struct InfoPing {
        int pingId;
    };

    struct InfoPlayer {
        bool connected;
        bool alive;
        short pos_x;
        short pos_y;
    };

    using InfoPlayers = InfoPlayer[PLAYERS_PER_ROOM];

    struct Entity {
        short type;
        short pos_x;
        short pos_y;
    };

    using Entities = std::vector<Entity>;

    static my_socket::Buffer strToBuffer(const std::string &str)
    {
        return {str.begin(), str.end()};
    }

    static std::string bufferToStr(const my_socket::Buffer &data)
    {
        return {data.begin(), data.end()};
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

#endif //CPP_RTYPE_2019_PROTOCOLUDP_HPP
