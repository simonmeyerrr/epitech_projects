/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneMainMenu.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENEMAINMENU_HPP
# define OOP_INDIE_STUDIO_2018_SCENEMAINMENU_HPP

#include "../AScene.hpp"

class SceneMainMenu : public AScene {
public:
    enum {
        GUI_ID_CREATE_GAME = 100,
        GUI_ID_JOIN_GAME,
        GUI_ID_SETTINGS,
        GUI_ID_GENERAL_SETTINGS,
        GUI_ID_CREDIT,
        GUI_ID_EXIT
    };
    ~SceneMainMenu() override;
    SceneMainMenu(IrrlichtDevice &device, MyEventReceiver &event, Settings
    &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

private:
    irr::video::ITexture *_background;
};

#endif /* OOP_INDIE_STUDIO_2018_SCENEMAINMENU_HPP */
