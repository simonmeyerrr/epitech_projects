/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneSettings.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENESETTINGS_HPP
#define OOP_INDIE_STUDIO_2018_SCENESETTINGS_HPP

#include "../AScene.hpp"

class SceneSettings : public AScene {
public:
    enum {
        GUI_ID_RETURN = 100,
        GUI_ID_SAVE = 101,
        GUI_ID_SET_NAME = 300,
        GUI_ID_SET_DOWN = 301,
        GUI_ID_SET_VALUE = 302,
        GUI_ID_SET_UP = 303,
    };
    ~SceneSettings() override;
    SceneSettings(IrrlichtDevice &device, MyEventReceiver &event, Settings
    &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

private:
    Settings _setCopy;
    irr::video::ITexture *_background;
};

#endif /* OOP_INDIE_STUDIO_2018_SCENESETTINGS_HPP */
