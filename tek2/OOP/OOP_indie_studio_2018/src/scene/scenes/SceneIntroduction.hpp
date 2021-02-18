/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneIntroduction.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENEINTRODUCTION_HPP
# define OOP_INDIE_STUDIO_2018_SCENEINTRODUCTION_HPP

#include <chrono>
#include <ctime>
#include "../AScene.hpp"

class SceneIntroduction : public AScene {
public:
    ~SceneIntroduction() override;
    SceneIntroduction(IrrlichtDevice &device, MyEventReceiver &event, Settings
    &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

private:
    using Chrono = std::chrono::time_point<std::chrono::high_resolution_clock>;

    Chrono _chrono;
    irr::video::ITexture *_textures[24];
};

#endif /* OOP_INDIE_STUDIO_2018_SCENEINTRODUCTION_HPP */
