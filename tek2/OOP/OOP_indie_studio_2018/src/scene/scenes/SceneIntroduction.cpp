/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneIntroduction.cpp
*/

#include <iostream>
#include "Config.hpp"
#include "Consts.hpp"
#include "SceneIntroduction.hpp"

SceneIntroduction::~SceneIntroduction()
{
    _device.smgr()->clear();
    _device.gui()->clear();
    _device.driver()->removeAllTextures();
}

SceneIntroduction::SceneIntroduction(IrrlichtDevice &device,
    MyEventReceiver &event, Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio),
    _chrono(std::chrono::high_resolution_clock::now()), _textures()
{
    _device.driver()->setTextureCreationFlag(
        irr::video::ETCF_OPTIMIZED_FOR_SPEED, true);
    for (int i = 0; i < 24; i++) {
        auto path = std::string(ASSETS_PATH_STR "textures/intro/") +
            std::to_string(i + 1) + ".jpg";
        _textures[i] = _device.driver()->getTexture(path.c_str());
        if (!_textures[i])
            throw;
    }
    _device.driver()->setTextureCreationFlag(
        irr::video::ETCF_OPTIMIZED_FOR_SPEED, false);
    _chrono = std::chrono::high_resolution_clock::now();
    _audio.playSound(SOUND_INTRO);
}

ChangeScene SceneIntroduction::update()
{
    auto time = std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - _chrono).count();
    if (time > (1000.0 / 20.0) * 50)
        return { true, SCENE_ANIM};
    return { false, SCENE_NONE };
}

void SceneIntroduction::display(double diff)
{
    auto time = (int)std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - _chrono).count();
    int image = time / (1000 / 20);

    if (image >= 24)
        image = 23;
    if (image >= 0)
        _device.driver()->draw2DImage(_textures[image],
            {0, 0, (int)_device.width(), (int)_device.height()},
            {0, 0, 1600, 900});
}