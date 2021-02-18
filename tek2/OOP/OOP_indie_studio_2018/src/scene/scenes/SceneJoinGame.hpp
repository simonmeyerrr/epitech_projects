/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneJoinGame.hpp
*/
#ifndef OOP_INDIE_STUDIO_2018_SCENEJOINGAME_HPP
# define OOP_INDIE_STUDIO_2018_SCENEJOINGAME_HPP

#include "../AScene.hpp"

class SceneJoinGame : public AScene {
public:
    enum {
        GUI_ID_MAIN_MENU = 100,
        GUI_ID_JOIN_GAME,
        GUI_ID_FIELD_IP,
        GUI_ID_SELECT
    };
    ~SceneJoinGame() override;
    SceneJoinGame(IrrlichtDevice &device, MyEventReceiver &event, Settings
    &settings, Audio &audio);
    void ipAppend(wchar_t c);

    ChangeScene update() override;
    void display(double diff) override;
private:
    irr::gui::IGUIEditBox *_ipEditBox;
    irr::gui::IGUIComboBox *_select;
    irr::video::ITexture *_background;
};


#endif /* OOP_INDIE_STUDIO_2018_SCENEJOINGAME_HPP */
