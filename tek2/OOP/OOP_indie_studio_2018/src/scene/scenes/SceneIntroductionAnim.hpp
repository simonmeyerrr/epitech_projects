/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneIntroductionAnim.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENEINTRODUCTIONANIM_HPP
#define OOP_INDIE_STUDIO_2018_SCENEINTRODUCTIONANIM_HPP

#include "../../game/IntroAnimBack.hpp"
#include "../AScene.hpp"


class SceneIntroAnim : public AScene {
public:
    ~SceneIntroAnim() override;
    SceneIntroAnim(IrrlichtDevice &device, MyEventReceiver &event, Settings
    &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

private:
   IntroAnimBack _back;
};


#endif /* OOP_INDIE_STUDIO_2018_SCENEINTRODUCTIONANIM_HPP */
