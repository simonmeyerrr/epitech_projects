/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneCreateGame.cpp
*/

#include <cwchar>
#include "SceneCreateGame.hpp"
#include "Config.hpp"
#include "Consts.hpp"

SceneCreateGame::~SceneCreateGame()
{
    _device.smgr()->clear();
    _device.gui()->clear();
}

SceneCreateGame::SceneCreateGame(IrrlichtDevice &device, MyEventReceiver &event,
    Settings &settings, Audio &audio
)
    : AScene(device, event, settings, audio), _setCopy(settings),
    _lamas{{nullptr, nullptr}, {nullptr, nullptr}, {nullptr, nullptr},
        {nullptr, nullptr}}, _save(nullptr), _map(nullptr),
    _background(_device.driver()->getTexture(ASSETS_PATH_STR "textures/background2.png"))
{
    _audio.playMusic(MUSIC_MENU);
    _responsiveGui.addButton(L"Main menu", GUI_ID_MAIN_MENU, {45, 98},
        {250, 35}, ResponsiveGui::ALI_X_RIGHT, ResponsiveGui::ALI_Y_DOWN);
    _responsiveGui.addButton(L"Launch game", GUI_ID_LAUNCH_GAME, {55, 98},
        {250, 35}, ResponsiveGui::ALI_X_LEFT, ResponsiveGui::ALI_Y_DOWN);
    _save = _device.gui()->addCheckBox(_settings.settings.from_file,
        {0, 0, 400, 35}, nullptr, GUI_ID_BOOL_SAVE, L" Load game from save");
    _responsiveGui.addElement(_save, {45, 90}, {400, 35},
        ResponsiveGui::ALI_X_RIGHT, ResponsiveGui::ALI_Y_DOWN);
    _map = _device.gui()->addCheckBox(_settings.settings.map_complex,
        {0, 0, 500, 35}, nullptr, GUI_ID_MAP_COMPLEX, L" Generate complex map");
    _responsiveGui.addElement(_map, {55, 90}, {500, 35},
        ResponsiveGui::ALI_X_LEFT, ResponsiveGui::ALI_Y_DOWN);
    for (int i = 0; i < PLAYER_NUMBER; i++) {
        _responsiveGui.addButton(L"<", GUI_ID_PREV_TYPE + i * 10,
            {10.f + (i % 2 == 0 ? 0 : 50), 5.f + (i / 2 == 0 ? 0 : 50)},
            {35, 35});
        _responsiveGui.addButton(L">", GUI_ID_NEXT_TYPE + i * 10,
            {40.f + (i % 2 == 0 ? 0 : 50), 5.f + (i / 2 == 0 ? 0 : 50)},
            {35, 35});
        auto str = (*PlayerTypeString.find(
            _setCopy.settings.players[i].type)).second;
        _responsiveGui.addText(std::wstring(str.begin(), str.end()).c_str(),
            GUI_ID_TYPE_NAME + i * 10,
            {25.f + (i % 2 == 0 ? 0 : 50), 5.f + (i / 2 == 0 ? 0 : 50)},
            {120, 35});
        _responsiveGui.addButton(L"<", GUI_ID_PREV_SKIN + i * 10,
            {10.f + (i % 2 == 0 ? 0 : 50), 25.f + (i / 2 == 0 ? 0 : 50)},
            {35, 35});
        _responsiveGui.addButton(L">", GUI_ID_NEXT_SKIN + i * 10,
            {40.f + (i % 2 == 0 ? 0 : 50), 25.f + (i / 2 == 0 ? 0 : 50)},
            {35, 35});
    }
    _device.smgr()->addCameraSceneNode(nullptr, {0, 0, -6 * BLOCK_SIZE},
        {0, 0, 0});
    addLamasticots();
}

ChangeScene SceneCreateGame::update()
{
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_ESCAPE) ||
        _eventReceiver.isButtonClicked(GUI_ID_MAIN_MENU)) {
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_MAIN_MENU};
    }
    if (_eventReceiver.isKeyDown(irr::EKEY_CODE::KEY_RETURN) ||
        _eventReceiver.isButtonClicked(GUI_ID_LAUNCH_GAME)) {
        _settings.create_game = true;
        _setCopy.settings.from_file = _save->isChecked();
        _setCopy.settings.map_complex = _map->isChecked();
        _settings = _setCopy;
        _audio.playSound(SOUND_CLICK);
        return {true, SCENE_IN_GAME};
    }
    for (int i = 0; i < PLAYER_NUMBER; i++) {
        if (_eventReceiver.isButtonClicked(GUI_ID_PREV_TYPE + i * 10))
            changeType(i, false);
        if (_eventReceiver.isButtonClicked(GUI_ID_NEXT_TYPE + i * 10))
            changeType(i, true);
        if (_eventReceiver.isButtonClicked(GUI_ID_PREV_SKIN + i * 10))
            changeSkin(i, false);
        if (_eventReceiver.isButtonClicked(GUI_ID_NEXT_SKIN + i * 10))
            changeSkin(i, true);
    }
    return {false, SCENE_NONE};
}

void SceneCreateGame::display(double diff)
{
    _device.driver()->draw2DImage(_background,
        { 0, 0, (int)_device.width(), (int)_device.height() },
        { 0, 0, 1600, 900 });
    _device.smgr()->drawAll();
    _responsiveGui.drawElements();
}

void SceneCreateGame::addLamasticots()
{
    auto mesh = _device.smgr()->getMesh(LamasticotModel.c_str());
    if (!mesh)
        throw;
    for (int i = 0; i < PLAYER_NUMBER; i++) {
        auto node = _device.smgr()->addAnimatedMeshSceneNode(mesh);
        auto texture = _device->getVideoDriver()->getTexture(
            PlayerSkinPath.at(_settings.settings.players[i].skin).c_str());
        if (!node || !texture)
            throw;
        node->setPosition({(i % 2 == 0 ? -4 : 4) * BLOCK_SIZE,
            (i / 2 == 0 ? 1 : -3) * BLOCK_SIZE, 0});
        node->setFrameLoop(0, 15);
        node->setAnimationSpeed(30);
        node->setRotation({0, -90, 0});
        node->setVisible(_setCopy.settings.players[i].type != PLAYER_NONE);
        node->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
        node->setMaterialTexture(0, texture);
        _lamas[i] = {node, texture};
    }
}

void SceneCreateGame::changeType(int player_nb, bool up)
{
    _audio.playSound(SOUND_CLICK);
    auto &type = _setCopy.settings.players[player_nb].type;

    switch (type) {
    case PLAYER_NONE:
        type = (up ? PLAYER_LOCAL : PLAYER_AI);
        break;
    case PLAYER_LOCAL:
        type = (up ? PLAYER_EXTERN : PLAYER_NONE);
        break;
    case PLAYER_EXTERN:
        type = (up ? PLAYER_AI : PLAYER_LOCAL);
        break;
    case PLAYER_AI:
        type = (up ? PLAYER_NONE : PLAYER_EXTERN);
        break;
    default:
        type = PLAYER_NONE;
    }
    auto str = (*PlayerTypeString.find(type)).second;
    _responsiveGui.changeText(GUI_ID_TYPE_NAME + player_nb * 10, str);
    if (type == PLAYER_NONE)
        _lamas[player_nb].first->setVisible(false);
    else
        _lamas[player_nb].first->setVisible(true);
}

void SceneCreateGame::changeSkin(int player_nb, bool up)
{
    _audio.playSound(SOUND_CLICK);
    auto &skin = _setCopy.settings.players[player_nb].skin;

    switch (skin) {
    case LAMA_BRAUN:
        skin = (up ? LAMA_BLACK : LAMA_PURPLE);
        break;
    case LAMA_BLACK:
        skin = (up ? LAMA_WHITE : LAMA_BRAUN);
        break;
    case LAMA_WHITE:
        skin = (up ? LAMA_RED : LAMA_BLACK);
        break;
    case LAMA_RED:
        skin = (up ? LAMA_BLUE : LAMA_WHITE);
        break;
    case LAMA_BLUE:
        skin = (up ? LAMA_GREEN : LAMA_RED);
        break;
    case LAMA_GREEN:
        skin = (up ? LAMA_YELLOW : LAMA_BLUE);
        break;
    case LAMA_YELLOW:
        skin = (up ? LAMA_PURPLE : LAMA_GREEN);
        break;
    case LAMA_PURPLE:
        skin = (up ? LAMA_BRAUN : LAMA_YELLOW);
        break;
    default:
        skin = LAMA_BRAUN;
    }
    auto texture = _device->getVideoDriver()->getTexture(
        PlayerSkinPath.at(skin).c_str());
    if (!texture)
        throw;
    _lamas[player_nb].first->setMaterialTexture(0, texture);
    _lamas[player_nb].second = texture;
}