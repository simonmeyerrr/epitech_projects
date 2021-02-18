/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IndieStudio.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_INDIESTUDIO_HPP
    #define OOP_INDIE_STUDIO_2018_INDIESTUDIO_HPP

#include <chrono>
#include <ctime>
#include "irrlicht/IrrlichtDevice.hpp"
#include "irrlicht/MyEventReceiver.hpp"
#include "Settings.hpp"
#include "scene/SceneFactory.hpp"

using Chrono = std::chrono::time_point<std::chrono::high_resolution_clock>;

class IndieStudio {
public:
    ~IndieStudio() = default;
    IndieStudio();

    void loop();
    void changeScene(SceneType type);

private:
    bool display(Chrono &chrono);
    bool update(Chrono &chrono);

    MyEventReceiver _eventReceiver;
    Settings _settings;
    IrrlichtDevice _device;
    Audio _audio;
    SceneType _sceneType;
    ScenePtr _scene;
};

#endif /* OOP_INDIE_STUDIO_2018_INDIESTUDIO_HPP */
