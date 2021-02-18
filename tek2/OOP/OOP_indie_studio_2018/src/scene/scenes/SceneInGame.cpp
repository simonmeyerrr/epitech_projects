/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneInGame.cpp
*/

#include <iostream>
#include "SceneInGame.hpp"
#include "Config.hpp"
#include "Consts.hpp"
#include "../../game/player/AiPlayer.hpp"

SceneInGame::~SceneInGame()
{
    _device.smgr()->clear();
    _device.gui()->clear();
    _device.driver()->removeAllTextures();
}

SceneInGame::SceneInGame(IrrlichtDevice &device, MyEventReceiver &event,
    Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio), _started(false), _back(nullptr),
    _players{nullptr, nullptr, nullptr, nullptr}, _displayGame(device, audio),
    _menu(device), _menu_active(false)
{
    _audio.playMusic(MUSIC_GAME);
    _responsiveGui.addText(L"", GUI_ID_FPS, {50, 0}, {300, 35},
        ResponsiveGui::ALI_X_CENTER, ResponsiveGui::ALI_Y_UP);
    _responsiveGui.addText(L"", GUI_ID_STATE, {50, 50}, {300, 150});
    if (_settings.create_game)
        _back.reset(new GameBack(settings));
    if (_back && _back->hasError())
        return;
    for (int i = 0; _settings.create_game && i < PLAYER_NUMBER; i++) {
        if (_settings.settings.players[i].type == PLAYER_LOCAL)
            _players[i].reset(new Player(i, i, settings.my_ip));
        else if (_settings.settings.players[i].type == PLAYER_AI)
            _players[i].reset(new AiPlayer(i, i, settings.my_ip, _settings));
        if (_players[i] && _players[i]->hasError())
            return;
    }
    if (!_settings.create_game) {
        _players[0].reset(new Player(0, settings.settings.join_nb,
            settings.settings.join_ip));
    }
    _menu.addButton(L"Resume", GUI_ID_RESUME, {50, 20}, {250, 35});
    if (_back)
        _menu.addButton(L"Save the game", GUI_ID_SAVE, {50, 40}, {250, 35});
    _menu.addButton(L"Quit the game", GUI_ID_QUIT, {50, 60}, {250, 35});
    if (_back)
        _menu.addButton(L"Save and quit", GUI_ID_SAVE_QUIT, {50, 80}, {250, 35});
}

ChangeScene SceneInGame::update()
{
    if (_back && _back->hasError())
        return {true, _settings.create_game ? SCENE_CREATE_GAME : SCENE_JOIN_GAME};
    for (int i = 0; i < PLAYER_NUMBER; i++) {
        if (_players[i] && _players[i]->hasError())
            return {true, _settings.create_game ? SCENE_CREATE_GAME : SCENE_JOIN_GAME};
    }
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_ESCAPE)) {
        _audio.playSound(SOUND_CLICK);
        _menu_active = !_menu_active;
        _eventReceiver.reset();
    }
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_RETURN) && _back) {
        _audio.playSound(SOUND_CLICK);
        _started = _back->startGame();
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_RESUME)) {
        _audio.playSound(SOUND_CLICK);
        _menu_active = false;
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_SAVE)) {
        _back->saveGame();
        _audio.playSound(SOUND_CLICK);
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_QUIT)) {
        _audio.playSound(SOUND_CLICK);
        return {true, _settings.create_game ? SCENE_CREATE_GAME : SCENE_JOIN_GAME};
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_SAVE_QUIT)) {
        _back->saveGame();
        _audio.playSound(SOUND_CLICK);
        return {true, _settings.create_game ? SCENE_CREATE_GAME : SCENE_JOIN_GAME};
    }
    for (int i = 0; i < PLAYER_NUMBER; i++) {
        if (_players[i])
            _players[i]->update(_settings.settings.keys[i], _eventReceiver);
    }
    return {false, SCENE_NONE};
}

void SceneInGame::display(double diff)
{
    #ifdef DEBUG
    _responsiveGui.changeText(GUI_ID_FPS, std::to_string((1000.0 / diff)));
    #endif
    _responsiveGui.changeText(GUI_ID_STATE, displayGame());
    _responsiveGui.drawElements();
    if (_menu_active) {
        _device.driver()->draw2DRectangle({200, 0, 0, 0},
            {0, 0, (int)_device.width(), (int)_device.height()});
        _menu.drawElements();
    }
}

std::string SceneInGame::displayGame()
{
    bool ready = true;
    const GameStats *game = (_back ? &(_back->getGame()) : nullptr);

    for (int i = 0; !game && i < PLAYER_NUMBER; i++) {
        if (_players[i])
            game = _players[i]->getGame();
    }
    _displayGame.display(game);
    for (int j = 0; j < PLAYER_NUMBER; j++) {
        if (game && game->players[j].exist && !game->players[j].connected)
            ready = false;
    }
    if (game && game->started)
        return "";
    else if (ready && _back)
        return "Press Enter to start the game";
    else if (ready)
        return "Waiting for the game owner to start the game";
    else if (_back)
        return "Waiting for other players\nIp: " + _settings.my_ip;
    else
        return "Waiting for other players";
}