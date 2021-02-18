/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneFactory.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENEFACTORY_HPP
    #define OOP_INDIE_STUDIO_2018_SCENEFACTORY_HPP

#include "scenes/SceneSplashScreen.hpp"
#include "scenes/SceneIntroduction.hpp"
#include "scenes/SceneMainMenu.hpp"
#include "scenes/SceneCreateGame.hpp"
#include "scenes/SceneJoinGame.hpp"
#include "scenes/SceneInGame.hpp"
#include "scenes/SceneSettings.hpp"
#include "scenes/SceneKeySettings.hpp"
#include "scenes/SceneCredit.hpp"
#include "scenes/SceneIntroductionAnim.hpp"

class SceneFactory {
public:
    static IScene *createScene(SceneType scene, IrrlichtDevice &device,
        MyEventReceiver &event, Settings &settings, Audio &audio)
    {
        event.reset();
        switch (scene) {
        case SCENE_SPLASH_SCREEN:
            return new SceneSplashScreen(device, event, settings, audio);
        case SCENE_INTRODUCTION:
            return new SceneIntroduction(device, event, settings, audio);
        case SCENE_MAIN_MENU:
            return new SceneMainMenu(device, event, settings, audio);
        case SCENE_CREATE_GAME:
            return new SceneCreateGame(device, event, settings, audio);
        case SCENE_JOIN_GAME:
            return new SceneJoinGame(device, event, settings, audio);
        case SCENE_IN_GAME:
            return new SceneInGame(device, event, settings, audio);
        case SCENE_SETTINGS:
            return new SceneSettings(device, event, settings, audio);
        case SCENE_KEY_SETTINGS:
            return new SceneKeySettings(device, event, settings, audio);
        case SCENE_CREDIT:
            return new SceneCredit(device, event, settings, audio);
        case SCENE_ANIM:
            return new SceneIntroAnim(device, event, settings, audio);
        default:
            return nullptr;
        }
    }
};

#endif /* OOP_INDIE_STUDIO_2018_SCENEFACTORY_HPP */
