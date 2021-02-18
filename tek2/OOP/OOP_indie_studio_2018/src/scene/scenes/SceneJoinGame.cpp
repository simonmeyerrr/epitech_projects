/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneJoinGame.cpp
*/

#include <cstring>
#include <cwchar>
#include "SceneJoinGame.hpp"
#include "Config.hpp"

SceneJoinGame::~SceneJoinGame()
{
    _device.smgr()->clear();
    _device.gui()->clear();
}

SceneJoinGame::SceneJoinGame(IrrlichtDevice &device, MyEventReceiver &event,
    Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio), _ipEditBox(nullptr),
    _select(nullptr), _background(_device.driver()->getTexture(ASSETS_PATH_STR "textures/background2.png"))
{
    _audio.playMusic(MUSIC_MENU);
    _responsiveGui.addText(L"Join game", -1, {50, 2}, {250, 35},
        ResponsiveGui::ALI_X_CENTER, ResponsiveGui::ALI_Y_UP);
    _responsiveGui.addButton(L"Main menu", GUI_ID_MAIN_MENU, {45, 98},
        {250, 35}, ResponsiveGui::ALI_X_RIGHT, ResponsiveGui::ALI_Y_DOWN);
    _responsiveGui.addButton(L"Launch game", GUI_ID_JOIN_GAME, {55, 98},
        {250, 35}, ResponsiveGui::ALI_X_LEFT, ResponsiveGui::ALI_Y_DOWN);
    auto str = std::string(settings.settings.join_ip);
    _ipEditBox = _device.gui()->addEditBox(
        std::wstring(str.begin(), str.end()).c_str(), {0, 0, 300, 35}, true, 0,
        GUI_ID_FIELD_IP);
    _ipEditBox->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
        irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
    _responsiveGui.addElement(_ipEditBox, {50, 31}, {300, 35},
        ResponsiveGui::ALI_X_CENTER, ResponsiveGui::ALI_Y_UP);
    _responsiveGui.addText(L"Enter the ip of the game owner", -1, {50, 29},
        {500, 35}, ResponsiveGui::ALI_X_CENTER, ResponsiveGui::ALI_Y_DOWN);
    _responsiveGui.addText(L"Select your player number", -1, {50, 59},
        {500, 35}, ResponsiveGui::ALI_X_CENTER, ResponsiveGui::ALI_Y_DOWN);
    _select = _device.gui()->addComboBox({0, 0, 200, 40}, nullptr, -1);
    _select->addItem(L"  Player 1", 0);
    _select->addItem(L"  Player 2", 1);
    _select->addItem(L"  Player 3", 2);
    _select->addItem(L"  Player 4", 3);
    _select->setSelected(_settings.settings.join_nb);
    _responsiveGui.addElement(_select, {50, 61}, {250, 40},
        ResponsiveGui::ALI_X_CENTER, ResponsiveGui::ALI_Y_UP);
}

ChangeScene SceneJoinGame::update()
{
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_ESCAPE) ||
        _eventReceiver.isButtonClicked(GUI_ID_MAIN_MENU)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_MAIN_MENU};
    }
    if ((_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_RETURN) ||
        _eventReceiver.isButtonClicked(GUI_ID_JOIN_GAME)) &&
        std::wstring(_ipEditBox->getText()).size() <= 19) {
        std::wstring ws(_ipEditBox->getText());
        std::string join_ip(ws.begin(), ws.end());
        if (join_ip.size() > 19)
            return {false, SCENE_NONE};
        memset(_settings.settings.join_ip, '\0', 20);
        strcpy(_settings.settings.join_ip, join_ip.c_str());
        _settings.settings.join_nb = _select->getSelected();
        _settings.create_game = false;
        Settings::saveSettings(_settings.settings);
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_IN_GAME};
    }
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_KEY_7)) {
        ipAppend(L'7');
        _eventReceiver.reset();
    }
    return {false, SCENE_NONE};
}

void SceneJoinGame::display(double diff)
{
    _device.driver()->draw2DImage(_background,
        { 0, 0, (int)_device.width(), (int)_device.height() },
        { 0, 0, 1600, 900 });
    _responsiveGui.drawElements();
}

void SceneJoinGame::ipAppend(wchar_t c)
{
    irr::core::stringw newString(_ipEditBox->getText());
    newString += c;
    _ipEditBox->setText(newString.c_str());
    irr::SEvent event;
    event.EventType = irr::EET_KEY_INPUT_EVENT;
    event.KeyInput.Char = 0;
    event.KeyInput.Key = irr::EKEY_CODE::KEY_RIGHT;
    event.KeyInput.PressedDown = true;
    event.KeyInput.Shift = false;
    event.KeyInput.Control = false;
    _device->getGUIEnvironment()->postEventFromUser(event);
}
