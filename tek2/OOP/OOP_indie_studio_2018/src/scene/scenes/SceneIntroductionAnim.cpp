/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneIntroductionAnim.cpp
*/

#include "Consts.hpp"
#include "SceneIntroductionAnim.hpp"

SceneIntroAnim::~SceneIntroAnim()
{
    _device.smgr()->clear();
    _device.gui()->clear();
    _device.driver()->clearZBuffer();
}

SceneIntroAnim::SceneIntroAnim(IrrlichtDevice &device, MyEventReceiver &event,
    Settings &settings, Audio &audio)
    : AScene(device, event, settings, audio),
    _back(IntroAnimBack(device, audio))
{}

ChangeScene SceneIntroAnim::update()
{
    if (_eventReceiver.getLastKey().second)
        return {true, SCENE_MAIN_MENU};
    _back.update();
    return {false, SCENE_NONE};
}

void SceneIntroAnim::display(double diff)
{
    _device.smgr()->drawAll();
}
