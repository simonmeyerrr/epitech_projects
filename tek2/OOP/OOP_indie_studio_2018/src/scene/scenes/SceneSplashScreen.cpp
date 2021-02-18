/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneSplashScreen.cpp
*/

#include <iostream>
#include "Config.hpp"
#include "Consts.hpp"
#include "SceneSplashScreen.hpp"

SceneSplashScreen::~SceneSplashScreen()
{
    _device.smgr()->clear();
    _device.gui()->clear();
    _device.driver()->removeAllTextures();
}

SceneSplashScreen::SceneSplashScreen(IrrlichtDevice &device,
    MyEventReceiver &event, Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio),
    _chrono(std::chrono::high_resolution_clock::now()), _textures()
{
    _device.driver()->setTextureCreationFlag(
        irr::video::ETCF_OPTIMIZED_FOR_SPEED, true);
    for (int i = 0; i < 34; i++) {
        auto path = std::string(ASSETS_PATH_STR "textures/splash/") +
            std::to_string(i + 1) + ".jpg";
        _textures[i] = _device.driver()->getTexture(path.c_str());
        if (!_textures[i])
            throw;
    }
    _device.driver()->setTextureCreationFlag(
        irr::video::ETCF_OPTIMIZED_FOR_SPEED, false);
    _chrono = std::chrono::high_resolution_clock::now();
    _audio.playSound(SOUND_SPLASH);
}

ChangeScene SceneSplashScreen::update()
{
    auto time = std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - _chrono).count();
    if (time > (1000.0 / 20.0) * 40)
        return {true, SCENE_INTRODUCTION};
    return {false, SCENE_NONE};
}

void SceneSplashScreen::display(double diff)
{
    auto time = (int)std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - _chrono).count();
    int image = time / (1000 / 20);

    if (image >= 34)
        image = 33;
    if (image >= 0)
        _device.driver()->draw2DImage(_textures[image],
            {0, 0, (int)_device.width(), (int)_device.height()},
            {0, 0, 1600, 900});
}
