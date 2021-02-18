/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Player.cpp
*/

#include <iostream>
#include "Player.hpp"

Player::~Player()
{
    delete _game;
}

Player::Player(int priv_nb, int pub_nb, const std::string &ip)
    : _priv_nb(priv_nb), _pub_nb(pub_nb), _client(ip, 8001 + pub_nb),
    _game(nullptr)
{
}

bool Player::hasError() const
{
    return _client.hasError();
}

void Player::update(const KeySet &set, MyEventReceiver &event)
{
    Action action = {MAGIC_NUMBER, false, DIR_UP, false};

    if (event.isKeyDown((irr::EKEY_CODE)set.up)) {
        action.move = true;
        action.dir = DIR_UP;
    } else if (event.isKeyDown((irr::EKEY_CODE)set.left)) {
        action.move = true;
        action.dir = DIR_LEFT;
    } else if (event.isKeyDown((irr::EKEY_CODE)set.down)) {
        action.move = true;
        action.dir = DIR_DOWN;
    } else if (event.isKeyDown((irr::EKEY_CODE)set.right)) {
        action.move = true;
        action.dir = DIR_RIGHT;
    }
    if (event.isKeyDown((irr::EKEY_CODE)set.action)) {
        action.use_power = true;
    }
    _client.sendMessage(&action);
    auto new_game = _client.getMessage();
    if (new_game) {
        delete _game;
        _game = new_game;
    }
}
