/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneKeySettings.cpp
*/

#include "SceneKeySettings.hpp"
#include "../../irrlicht/ResponsiveGui.hpp"
#include <iostream>

SceneKeySettings::~SceneKeySettings()
{
    _device.smgr()->clear();
    _device.gui()->clear();
    _device.driver()->clearZBuffer();
}

SceneKeySettings::SceneKeySettings(IrrlichtDevice &device,
    MyEventReceiver &event, Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio), _setCopy(settings),
    _keyChangeId(0), _background(_device.driver()->getTexture(ASSETS_PATH_STR "textures/background2.png"))
{
    _responsiveGui.addButton(L"Main menu", GUI_ID_RETURN, {45, 98}, {250, 35},
        ResponsiveGui::ALI_X_RIGHT, ResponsiveGui::ALI_Y_DOWN);
    _responsiveGui.addButton(L"Save settings", GUI_ID_SAVE, {55, 98}, {250, 35},
        ResponsiveGui::ALI_X_LEFT, ResponsiveGui::ALI_Y_DOWN);

    /* SOUND SETTINGS */
    _responsiveGui.addText(L"SOUND SETTINGS", 0, {50, 10}, {300, 30});
    _responsiveGui.addText(L"MASTER VOLUME", GUI_ID_MASTER_SB + 10, {40, 20},
        {300, 30}, ResponsiveGui::ALI_X_RIGHT);
    _responsiveGui.addText(L"MUSIC VOLUME", GUI_ID_MUSIC_SB + 10, {40, 25},
        {300, 30}, ResponsiveGui::ALI_X_RIGHT);
    _responsiveGui.addText(L"SFX VOLUME", GUI_ID_SFX_SB + 10, {40, 30},
        {300, 30}, ResponsiveGui::ALI_X_RIGHT);
    _responsiveGui.addScrollBar(GUI_ID_MASTER_SB, true, {40, 20}, {500, 30},
        settings.settings.general_volume, ResponsiveGui::ALI_X_LEFT);
    _responsiveGui.addScrollBar(GUI_ID_MUSIC_SB, true, {40, 25}, {500, 30},
        settings.settings.music_volume, ResponsiveGui::ALI_X_LEFT);
    _responsiveGui.addScrollBar(GUI_ID_SFX_SB, true, {40, 30}, {500, 30},
        settings.settings.sfx_volume, ResponsiveGui::ALI_X_LEFT);

    /* KEY BINDING */
    _responsiveGui.addText(L"CONTROLS", 0, {50.f, 45.f}, {200, 35});
    _responsiveGui.addText(L"UP", GUI_ID_STR_UP, {20.f, 60.f}, {100, 35},
        ResponsiveGui::ALI_X_RIGHT);
    _responsiveGui.addText(L"LEFT", GUI_ID_STR_DOWN, {20.f, 65.f}, {100, 35},
        ResponsiveGui::ALI_X_RIGHT);
    _responsiveGui.addText(L"DOWN", GUI_ID_STR_LEFT, {20.f, 70.f}, {100, 35},
        ResponsiveGui::ALI_X_RIGHT);
    _responsiveGui.addText(L"RIGHT", GUI_ID_STR_RIGHT, {20.f, 75.f}, {100, 35},
        ResponsiveGui::ALI_X_RIGHT);
    _responsiveGui.addText(L"ACTION", GUI_ID_STR_ACTION, {20.f, 80.f},
        {100, 35}, ResponsiveGui::ALI_X_RIGHT);
    KeySet *keySets = _setCopy.settings.keys;
    for (int i = 0; i < PLAYER_NUMBER; i++) {
        keySets[i].up = settings.settings.keys[i].up;
        keySets[i].down = settings.settings.keys[i].down;
        keySets[i].left = settings.settings.keys[i].left;
        keySets[i].right = settings.settings.keys[i].right;
        keySets[i].action = settings.settings.keys[i].action;
        std::wstring str = L"PLAYER " + std::to_wstring(i + 1);
        float percentX = 30 + (i * 70 / irr::s32(PLAYER_NUMBER));
        _responsiveGui.addText(str.c_str(),
            -1, {percentX, 55}, {150, 35});
        _responsiveGui.addButton(keyMap[keySets[i].up].c_str(),
            GUI_ID_KEY_UP + i * GUI_ID_KEY_NBR, {percentX, 60}, {150, 35});
        _responsiveGui.addButton(keyMap[keySets[i].left].c_str(),
            GUI_ID_KEY_LEFT + i * GUI_ID_KEY_NBR, {percentX, 65}, {150, 35});
        _responsiveGui.addButton(keyMap[keySets[i].down].c_str(),
            GUI_ID_KEY_DOWN + i * GUI_ID_KEY_NBR, {percentX, 70}, {150, 35});
        _responsiveGui.addButton(keyMap[keySets[i].right].c_str(),
            GUI_ID_KEY_RIGHT + i * GUI_ID_KEY_NBR, {percentX, 75}, {150, 35});
        _responsiveGui.addButton(keyMap[keySets[i].action].c_str(),
            GUI_ID_KEY_ACTION + i * GUI_ID_KEY_NBR, {percentX, 80}, {150, 35});
        _keyRefs[GUI_ID_KEY_UP + i * GUI_ID_KEY_NBR] = &keySets[i].up;
        _keyRefs[GUI_ID_KEY_LEFT + i * GUI_ID_KEY_NBR] = &keySets[i].left;
        _keyRefs[GUI_ID_KEY_DOWN + i * GUI_ID_KEY_NBR] = &keySets[i].down;
        _keyRefs[GUI_ID_KEY_RIGHT + i * GUI_ID_KEY_NBR] = &keySets[i].right;
        _keyRefs[GUI_ID_KEY_ACTION + i * GUI_ID_KEY_NBR] = &keySets[i].action;
    }
}

ChangeScene SceneKeySettings::update()
{
    if (_keyChangeId) {
        updateKey();
        return {false, SCENE_NONE};
    }
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_ESCAPE) ||
        _eventReceiver.isButtonClicked(GUI_ID_RETURN)) {
        _audio.setGeneralVolume(_settings.settings.general_volume);
        _audio.setMusicVolume(_settings.settings.music_volume);
        _audio.setSoundVolume(_settings.settings.sfx_volume);
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_MAIN_MENU};
    }
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_RETURN) ||
        _eventReceiver.isButtonClicked(GUI_ID_SAVE)) {
        _audio.playSound(SOUND_CLICK);
        _settings = _setCopy;
        return {true, SCENE_MAIN_MENU};
    }
    for (int i = 0; i < PLAYER_NUMBER * GUI_ID_KEY_NBR; ++i) {
        int id = GUI_ID_KEY_UP + i;
        if (_eventReceiver.isButtonClicked(id))
            toggleKeyChange(GUI_ID_KEY_UP + i);
    }
    if (_eventReceiver.scrollBarMoved(GUI_ID_MASTER_SB)) {
        _setCopy.settings.general_volume = _eventReceiver.getScrollBarPos();
        _audio.setGeneralVolume(_setCopy.settings.general_volume);
        _audio.playSound(SOUND_CLICK);
    } else if (_eventReceiver.scrollBarMoved(GUI_ID_MUSIC_SB)) {
        _setCopy.settings.music_volume = _eventReceiver.getScrollBarPos();
        _audio.setMusicVolume(_setCopy.settings.music_volume);
        _audio.playSound(SOUND_CLICK);
    } else if (_eventReceiver.scrollBarMoved(GUI_ID_SFX_SB)) {
        _setCopy.settings.sfx_volume = _eventReceiver.getScrollBarPos();
        _audio.setSoundVolume(_setCopy.settings.sfx_volume);
        _audio.playSound(SOUND_CLICK);
    }
    return {false, SCENE_NONE};
}

void SceneKeySettings::display(double diff)
{
    _device.driver()->draw2DImage(_background,
        { 0, 0, (int)_device.width(), (int)_device.height() },
        { 0, 0, 1600, 900 });
    _responsiveGui.drawElements();
}

void SceneKeySettings::updateKey()
{
    if (!_eventReceiver.getLastKey().second)
        return;
    int newKey = _eventReceiver.getLastKey().first;
    if (newKey == irr::EKEY_CODE::KEY_ESCAPE) {
        _responsiveGui.changeText(_keyChangeId, std::string(
        keyMap[*_keyRefs[_keyChangeId]].begin(),
        keyMap[*_keyRefs[_keyChangeId]].end()));
        _keyChangeId = 0;
        _eventReceiver.reset();
        return;
    }
    if (!keyMap.count(newKey))
        return;
    for (auto ref : _keyRefs) {
        if (*ref.second == newKey) {
            *ref.second = 0;
            _responsiveGui.changeText(ref.first, "");
        }
    }
    *_keyRefs[_keyChangeId] = newKey;
    _responsiveGui.changeText(_keyChangeId,
        std::string(keyMap[newKey].begin(), keyMap[newKey].end()));
    _keyChangeId = 0;
    _eventReceiver.reset();
    _audio.playSound(SOUND_CLICK);
}

void SceneKeySettings::toggleKeyChange(int id)
{
    _responsiveGui.changeText(id, "[Press]");
    _keyChangeId = id;
}
