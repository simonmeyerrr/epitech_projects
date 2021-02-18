/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneMainMenu.cpp
*/

#include <iostream>
#include "SceneMainMenu.hpp"
#include "Config.hpp"

SceneMainMenu::~SceneMainMenu()
{
    _device.smgr()->clear();
    _device.gui()->clear();
    _device.driver()->clearZBuffer();
}

SceneMainMenu::SceneMainMenu(IrrlichtDevice &device, MyEventReceiver &event,
    Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio),
    _background(_device.driver()->getTexture(ASSETS_PATH_STR "textures/background.png"))
{
    _audio.playMusic(MUSIC_MENU);
    _responsiveGui.addButton(L"Create a game", GUI_ID_CREATE_GAME, {50, 40},
        {250, 35});
    _responsiveGui.addButton(L"Join a game", GUI_ID_JOIN_GAME, {50, 50},
        {250, 35});
    _responsiveGui.addButton(L"Game Settings", GUI_ID_SETTINGS, {50, 60}, {250, 35});
    _responsiveGui.addButton(L"Settings", GUI_ID_GENERAL_SETTINGS, {50, 70}, {250, 35});
    _responsiveGui.addButton(L"Credits", GUI_ID_CREDIT, {50, 80}, {250, 35});
    _responsiveGui.addButton(L"Exit", GUI_ID_EXIT, {50, 90}, {250, 35});
}

ChangeScene SceneMainMenu::update()
{
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_ESCAPE) ||
        _eventReceiver.isButtonClicked(GUI_ID_EXIT)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_NONE};
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_CREATE_GAME) ||
        _eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_RETURN)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_CREATE_GAME};
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_JOIN_GAME)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_JOIN_GAME};
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_SETTINGS)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_SETTINGS};
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_GENERAL_SETTINGS)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_KEY_SETTINGS};
    }
    if (_eventReceiver.isButtonClicked(GUI_ID_CREDIT)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_CREDIT};
    }
    return {false, SCENE_NONE};
}

void SceneMainMenu::display(double diff)
{
    _device.driver()->draw2DImage(_background,
        { 0, 0, (int)_device.width(), (int)_device.height() },
        { 0, 0, 1600, 900 });
    _responsiveGui.drawElements();
}