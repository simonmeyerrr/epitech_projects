/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IPlayer.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_IPLAYER_HPP
#define OOP_INDIE_STUDIO_2018_IPLAYER_HPP

#include "Structures.hpp"
#include "../TcpClient.hpp"
#include "../../Settings.hpp"
#include "../../irrlicht/MyEventReceiver.hpp"

class IPlayer {
public:
    virtual ~IPlayer() = default;

    virtual int getPrivateNb() const = 0;
    virtual int getPublicNb() const = 0;
    virtual const GameStats *getGame() = 0;
    virtual bool hasError() const = 0;

    virtual void update(const KeySet &set, MyEventReceiver &event) = 0;

};

#endif //OOP_INDIE_STUDIO_2018_IPLAYER_HPP
