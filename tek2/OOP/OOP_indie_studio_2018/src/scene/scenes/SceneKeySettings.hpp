/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneKeySettings.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENEKEYSETTINGS_HPP
#define OOP_INDIE_STUDIO_2018_SCENEKEYSETTINGS_HPP

#include "../AScene.hpp"


using KeyMap = std::map<int, std::wstring>;

static KeyMap keyMap = {
    {irr::EKEY_CODE::KEY_KEY_A, L"A"},
    {irr::EKEY_CODE::KEY_KEY_B, L"B"},
    {irr::EKEY_CODE::KEY_KEY_C, L"C"},
    {irr::EKEY_CODE::KEY_KEY_D, L"D"},
    {irr::EKEY_CODE::KEY_KEY_E, L"E"},
    {irr::EKEY_CODE::KEY_KEY_F, L"F"},
    {irr::EKEY_CODE::KEY_KEY_G, L"G"},
    {irr::EKEY_CODE::KEY_KEY_H, L"H"},
    {irr::EKEY_CODE::KEY_KEY_I, L"I"},
    {irr::EKEY_CODE::KEY_KEY_J, L"J"},
    {irr::EKEY_CODE::KEY_KEY_K, L"K"},
    {irr::EKEY_CODE::KEY_KEY_L, L"L"},
    {irr::EKEY_CODE::KEY_KEY_M, L"M"},
    {irr::EKEY_CODE::KEY_KEY_N, L"N"},
    {irr::EKEY_CODE::KEY_KEY_O, L"O"},
    {irr::EKEY_CODE::KEY_KEY_P, L"P"},
    {irr::EKEY_CODE::KEY_KEY_Q, L"Q"},
    {irr::EKEY_CODE::KEY_KEY_R, L"R"},
    {irr::EKEY_CODE::KEY_KEY_S, L"S"},
    {irr::EKEY_CODE::KEY_KEY_T, L"T"},
    {irr::EKEY_CODE::KEY_KEY_U, L"U"},
    {irr::EKEY_CODE::KEY_KEY_V, L"V"},
    {irr::EKEY_CODE::KEY_KEY_W, L"W"},
    {irr::EKEY_CODE::KEY_KEY_X, L"X"},
    {irr::EKEY_CODE::KEY_KEY_Y, L"Y"},
    {irr::EKEY_CODE::KEY_KEY_Z, L"Z"},
    {irr::EKEY_CODE::KEY_UP, L"UP"},
    {irr::EKEY_CODE::KEY_DOWN, L"DOWN"},
    {irr::EKEY_CODE::KEY_LEFT, L"LEFT"},
    {irr::EKEY_CODE::KEY_RIGHT, L"RIGHT"},
    {irr::EKEY_CODE::KEY_KEY_0, L"0"},
    {irr::EKEY_CODE::KEY_KEY_1, L"1"},
    {irr::EKEY_CODE::KEY_KEY_2, L"2"},
    {irr::EKEY_CODE::KEY_KEY_3, L"3"},
    {irr::EKEY_CODE::KEY_KEY_4, L"4"},
    {irr::EKEY_CODE::KEY_KEY_5, L"5"},
    {irr::EKEY_CODE::KEY_KEY_6, L"6"},
    {irr::EKEY_CODE::KEY_KEY_7, L"7"},
    {irr::EKEY_CODE::KEY_KEY_8, L"8"},
    {irr::EKEY_CODE::KEY_KEY_9, L"9"},
    {irr::EKEY_CODE::KEY_OEM_8, L"PRESS A KEY TO BIND"},
};

class SceneKeySettings : public AScene {
public:
    enum {
        GUI_ID_RETURN = 100,
        GUI_ID_SAVE = 101,
        GUI_ID_MASTER_SB = 102,
        GUI_ID_SFX_SB = 103,
        GUI_ID_MUSIC_SB = 104,
        GUI_ID_PLAYER_STR = 200,
        GUI_ID_STR_UP = 201,
        GUI_ID_STR_DOWN = 202,
        GUI_ID_STR_LEFT = 203,
        GUI_ID_STR_RIGHT = 204,
        GUI_ID_STR_ACTION = 205,
        GUI_ID_KEY_UP = 206,
        GUI_ID_KEY_DOWN = 207,
        GUI_ID_KEY_LEFT = 208,
        GUI_ID_KEY_RIGHT = 209,
        GUI_ID_KEY_ACTION = 210,
        GUI_ID_KEY_NBR = 5,
    };
    ~SceneKeySettings() override;
    SceneKeySettings(IrrlichtDevice &device, MyEventReceiver &event, Settings
    &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

    void updateKey();
    void toggleKeyChange(int id);
private:
    Settings _setCopy;
    std::map<int, int *> _keyRefs;
    int _keyChangeId;
    irr::video::ITexture *_background;
};

#endif //OOP_INDIE_STUDIO_2018_SCENEKEYSETTINGS_HPP
