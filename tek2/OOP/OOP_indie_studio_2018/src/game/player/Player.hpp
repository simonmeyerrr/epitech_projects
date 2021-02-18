/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Player.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_PLAYER_HPP
# define OOP_INDIE_STUDIO_2018_PLAYER_HPP

#include <memory>
#include "Structures.hpp"
#include "../TcpClient.hpp"
#include "../../Settings.hpp"
#include "../../irrlicht/MyEventReceiver.hpp"
#include "IPlayer.hpp"

class Player : public IPlayer {
public:
    ~Player() override;
    Player(int priv_nb, int pub_nb, const std::string &ip);

    int getPrivateNb() const override {return _priv_nb;}
    int getPublicNb() const override {return _pub_nb;}
    const GameStats *getGame() override {return _game;}
    bool hasError() const override;

    void update(const KeySet &set, MyEventReceiver &event) override;

protected:
    int _priv_nb;
    int _pub_nb;
    TcpClient _client;
    GameStats *_game;
};

using PlayerPtr = std::unique_ptr<Player>;

#endif /*OOP_INDIE_STUDIO_2018_PLAYER_HPP*/
