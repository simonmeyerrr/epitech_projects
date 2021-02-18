/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneSettings.cpp
*/

#include <iostream>
#include "SceneSettings.hpp"
#include "Config.hpp"
#include "Consts.hpp"

SceneSettings::~SceneSettings()
{
    _device.smgr()->clear();
    _device.gui()->clear();
    _device.driver()->clearZBuffer();
}

SceneSettings::SceneSettings(IrrlichtDevice &device, MyEventReceiver &event,
    Settings &settings, Audio &audio
)
    : AScene(device, event, settings, audio), _setCopy(settings), _background(
    _device.driver()->getTexture(ASSETS_PATH_STR "textures/background2.png"))
{
    _audio.playMusic(MUSIC_MENU);
    _responsiveGui.addButton(L"Main menu", GUI_ID_RETURN, {45, 98}, {250, 35},
        ResponsiveGui::ALI_X_RIGHT, ResponsiveGui::ALI_Y_DOWN);
    _responsiveGui.addButton(L"Save settings", GUI_ID_SAVE, {55, 98}, {250, 35},
        ResponsiveGui::ALI_X_LEFT, ResponsiveGui::ALI_Y_DOWN);
    auto size = ChangeGameSettings.size();
    for (unsigned int i = 0; i < size; ++i) {
        auto str = std::get<0>(ChangeGameSettings[i]);
        _responsiveGui.addText(std::wstring(str.begin(), str.end()).c_str(),
            GUI_ID_SET_NAME + i * 5, {50, 80 * ((float)i / size) + 10},
            {600, 35}, ResponsiveGui::ALI_X_RIGHT, ResponsiveGui::ALI_Y_CENTER);
        _responsiveGui.addButton(L"<", GUI_ID_SET_DOWN + i * 5,
            {60, 80 * ((float)i / size) + 10}, {35, 35});
        _responsiveGui.addButton(L">", GUI_ID_SET_UP + i * 5,
            {90, 80 * ((float)i / size) + 10}, {35, 35});
        str = std::get<1>(ChangeGameSettings[i])(_setCopy.settings.game);
        _responsiveGui.addText(std::wstring(str.begin(), str.end()).c_str(),
            GUI_ID_SET_VALUE + i * 5, {75, 80 * ((float)i / size) + 10},
            {150, 35});
    }
}

ChangeScene SceneSettings::update()
{
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_ESCAPE) ||
        _eventReceiver.isButtonClicked(GUI_ID_RETURN)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_MAIN_MENU};
    }
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_RETURN) ||
        _eventReceiver.isButtonClicked(GUI_ID_SAVE)) {
        _settings = _setCopy;
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_MAIN_MENU};
    }
    auto size = ChangeGameSettings.size();
    GameSettings &game = _setCopy.settings.game;
    for (unsigned int i = 0; i < size; ++i) {
        if (_eventReceiver.isButtonClicked(GUI_ID_SET_DOWN + i * 5)) {
            _audio.playSound(SOUND_CLICK);
            std::get<2>(ChangeGameSettings[i])(game, false);
            _responsiveGui.changeText(GUI_ID_SET_VALUE + i * 5,
                std::get<1>(ChangeGameSettings[i])(game));
            if (i > 1)
                _responsiveGui.changeText(GUI_ID_SET_VALUE + (i - 1) * 5,
                    std::get<1>(ChangeGameSettings[i - 1])(game));
        } else if (_eventReceiver.isButtonClicked(GUI_ID_SET_UP + i * 5)) {
            _audio.playSound(SOUND_CLICK);
            std::get<2>(ChangeGameSettings[i])(game, true);
            _responsiveGui.changeText(GUI_ID_SET_VALUE + i * 5,
                std::get<1>(ChangeGameSettings[i])(game));
        }
    }
    return {false, SCENE_NONE};
}

void SceneSettings::display(double diff)
{
    _device.driver()->draw2DImage(_background,
        {0, 0, (int)_device.width(), (int)_device.height()}, {0, 0, 1600, 900});
    _responsiveGui.drawElements();
}
