//
// Created by hugo on 11/26/19.
//

#ifndef CPP_RTYPE_2019_IGAMEOBJECT_HPP
#define CPP_RTYPE_2019_IGAMEOBJECT_HPP


#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../../../../ProtocolUDP.hpp"

class IGameObject
{
public:
    using ObjectType = enum {
        PLAYER1,
        PLAYER2,
        PLAYER3,
        PLAYER4
    };

    virtual void render(sf::RenderWindow &, sf::Vector2f) = 0;
    virtual void update() = 0;
};

using IGameObjectPtr = std::unique_ptr<IGameObject>;


#endif //CPP_RTYPE_2019_IGAMEOBJECT_HPP
