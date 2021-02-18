/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneCredit.cpp
*/

#include <iostream>
#include "SceneCredit.hpp"
#include "Config.hpp"

SceneCredit::~SceneCredit()
{
    _device.smgr()->clear();
    _device.gui()->clear();
}

SceneCredit::SceneCredit(IrrlichtDevice &device, MyEventReceiver &event,
    Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio), _background(_device.driver()->getTexture(ASSETS_PATH_STR "textures/background2.png"))
{
    _audio.playMusic(MUSIC_MENU);
    _responsiveGui.addButton(L"Return", GUI_ID_RETURN, {50, 95}, {250, 35});
    _responsiveGui.addText(L"Loup Masneri\nProject Manager\nVersatile Developer", -1, {25, 30}, {400, 105});
    _responsiveGui.addText(L"Ioannis Kesisoglou\nSound Designer\nVersatile Developute", -1, {25, 70}, {400, 105});
    _responsiveGui.addText(L"Leo Fornes\nAI Engineer\nVersatile Developer", -1, {50, 30}, {400, 105});
    _responsiveGui.addText(L"Quentin Jeanningros\nGraphic Designer\nVersatile Developer", -1, {50, 70}, {400, 105});
    _responsiveGui.addText(L"Remi Desmartin\nScrum Master\nVersatile Developer", -1, {75, 30}, {400, 105});
    _responsiveGui.addText(L"Simon Meyer\nProject Designer\nBack-End Engineer", -1, {75, 70}, {400, 105});
}

ChangeScene SceneCredit::update()
{
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_ESCAPE) ||
        _eventReceiver.isButtonClicked(GUI_ID_RETURN)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_MAIN_MENU};
    }
    return {false, SCENE_NONE};
}

void SceneCredit::display(double diff)
{
    _device.driver()->draw2DImage(_background,
        { 0, 0, (int)_device.width(), (int)_device.height() },
        { 0, 0, 1600, 900 });
    _responsiveGui.drawElements();
}