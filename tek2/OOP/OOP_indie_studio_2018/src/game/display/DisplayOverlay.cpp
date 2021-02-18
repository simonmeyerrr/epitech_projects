/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayOverlay.cpp
*/

#include <string>
#include "DisplayOverlay.hpp"

DisplayOverlay::DisplayOverlay(IrrlichtDevice &device, int nb)
    : _device(device), _nb(nb)
{
    _back = _device.gui()->addImage(
        _device.driver()->getTexture(ASSETS_PATH_STR "textures/overlay.png"),
        {0, 0});
    _connected = _device.gui()->addImage(
        _device.driver()->getTexture(ASSETS_PATH_STR "textures/connected.png"),
        {0, 0});
    _disconnected = _device.gui()->addImage(_device.driver()->getTexture(
        ASSETS_PATH_STR "textures/disconnected.png"), {0, 0});
    _player = _device.gui()->addStaticText(L"", {0, 0, 300, 35});
    changeText("Player " + std::to_string(nb + 1), _player);
    _rank = _device.gui()->addStaticText(L"", {0, 0, 300, 35});
    _speed = _device.gui()->addStaticText(L"", {0, 0, 300, 35});
    _bombs = _device.gui()->addStaticText(L"", {0, 0, 300, 35});
    _bombs_power = _device.gui()->addStaticText(L"", {0, 0, 300, 35});
}

void DisplayOverlay::display(const GameStats *game, Audio &audio)
{
    if (!game || !game->players[_nb].exist)
        return;
    drawImage(_back, {0, 0});
    drawImage(game->players[_nb].connected ? _connected : _disconnected, {200, 25});
    drawText(_player, {40, 35});

    changeText(game->players[_nb].rank != -1 ? std::to_string((int)game->players[_nb].rank) : "-", _rank);
    drawText(_rank, {80, 75});

    changeText(std::to_string(game->players[_nb].speed), _speed);
    drawText(_speed, {215, 75});

    changeText(std::to_string((int)game->players[_nb].ready_bomb) + " / " +
        std::to_string((int)game->players[_nb].max_bomb), _bombs);
    drawText(_bombs, {75, 120});

    changeText(std::to_string((int)game->players[_nb].bomb_power), _bombs_power);
    drawText(_bombs_power, {215, 120});
}

void DisplayOverlay::changeText(const std::string &str,
    irr::gui::IGUIStaticText *txt)
{
    if (!txt)
        return;
    txt->setText(std::wstring(str.begin(), str.end()).c_str());
}

void DisplayOverlay::drawText(irr::gui::IGUIStaticText *txt,
    const irr::core::position2di &pos)
{
    int x = 2;
    int y = 2;

    if (_nb % 2 != 0)
        x = _device.width() - 306;
    if (_nb / 2 != 0)
        y = _device.height() - 182;

    txt->setRelativePosition({x + pos.X, y + pos.Y});
    txt->draw();
}

void DisplayOverlay::drawImage(irr::gui::IGUIImage *image,
    const irr::core::position2di &pos)
{
    int x = 2;
    int y = 2;

    if (_nb % 2 != 0)
        x = _device.width() - 306;
    if (_nb / 2 != 0)
        y = _device.height() - 182;

    image->setRelativePosition({x + pos.X, y + pos.Y});
    image->draw();
}