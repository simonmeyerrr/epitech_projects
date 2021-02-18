/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayGame.cpp
*/
#include "DisplayGame.hpp"

DisplayGame::DisplayGame(IrrlichtDevice &device, Audio &audio)
    : _device(device), _audio(audio), _displayDecor(device), _displayMap(device),
    _displayPlayer{{device, 0}, {device, 1}, {device, 2}, {device, 3}},
    _displayOverlay{{device, 0}, {device, 1}, {device, 2}, {device, 3}}
{
}

void DisplayGame::display(const GameStats *game)
{
    _displayDecor.display(game, _audio);
    _displayMap.display(game, _audio);
    for (int i = 0; i < PLAYER_NUMBER; i++)
        _displayPlayer[i].display(game, _audio);
    _device.smgr()->drawAll();
    for (int i = 0; i < PLAYER_NUMBER; i++)
        _displayOverlay[i].display(game, _audio);
}