/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneSplashScreen.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENESPLASHSCREEN_HPP
# define OOP_INDIE_STUDIO_2018_SCENESPLASHSCREEN_HPP

#include <chrono>
#include <ctime>
#include "../AScene.hpp"

class SceneSplashScreen : public AScene {
public:
    ~SceneSplashScreen() override;
    SceneSplashScreen(IrrlichtDevice &device, MyEventReceiver &event, Settings
    &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

private:
    using Chrono = std::chrono::time_point<std::chrono::high_resolution_clock>;

    Chrono _chrono;
    irr::video::ITexture *_textures[34];
};

#endif /* OOP_INDIE_STUDIO_2018_SCENESPLASHSCREEN_HPP */
