/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneInGame.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENEINGAME_HPP
# define OOP_INDIE_STUDIO_2018_SCENEINGAME_HPP

#include "../AScene.hpp"
#include "../../game/GameBack.hpp"
#include "../../game/player/Player.hpp"
#include "../../game/display/DisplayGame.hpp"

class SceneInGame : public AScene {
public:
    enum {
        GUI_ID_FPS = 100,
        GUI_ID_STATE = 101,
        GUI_ID_RESUME = 102,
        GUI_ID_SAVE = 103,
        GUI_ID_QUIT = 104,
        GUI_ID_SAVE_QUIT = 105,
    };
    ~SceneInGame() override;
    SceneInGame(IrrlichtDevice &device, MyEventReceiver &event,
        Settings &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

private:
    std::string displayGame();

    bool _started;
    GameBackPtr _back;
    PlayerPtr _players[PLAYER_NUMBER];
    DisplayGame _displayGame;
    ResponsiveGui _menu;
    bool _menu_active;
};

#endif /* OOP_INDIE_STUDIO_2018_SCENEINGAME_HPP */
