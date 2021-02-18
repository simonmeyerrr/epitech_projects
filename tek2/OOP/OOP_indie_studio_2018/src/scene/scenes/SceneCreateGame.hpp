/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneCreateGame.hpp
*/
#ifndef OOP_INDIE_STUDIO_2018_SCENECREATEGAME_HPP
# define OOP_INDIE_STUDIO_2018_SCENECREATEGAME_HPP

#include "../AScene.hpp"

class SceneCreateGame : public AScene {
public:
    enum {
        GUI_ID_MAIN_MENU = 100,
        GUI_ID_LAUNCH_GAME = 101,
        GUI_ID_BOOL_SAVE = 102,
        GUI_ID_MAP_COMPLEX = 103,
        GUI_ID_PREV_TYPE = 200,
        GUI_ID_NEXT_TYPE = 201,
        GUI_ID_PREV_SKIN = 202,
        GUI_ID_NEXT_SKIN = 203,
        GUI_ID_TYPE_NAME = 204,
    };
    ~SceneCreateGame() override;
    SceneCreateGame(IrrlichtDevice &device, MyEventReceiver &event,
        Settings &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;
private:
    void addLamasticots();
    void changeType(int player_nb, bool up);
    void changeSkin(int player_nb, bool up);

    Settings _setCopy;
    std::pair<irr::scene::IAnimatedMeshSceneNode *, irr::video::ITexture *> _lamas[PLAYER_NUMBER];
    irr::gui::IGUICheckBox *_save;
    irr::gui::IGUICheckBox *_map;
    irr::video::ITexture *_background;
};

#endif /* OOP_INDIE_STUDIO_2018_SCENECREATEGAME_HPP */
