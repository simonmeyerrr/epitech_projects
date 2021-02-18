/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IndieStudio.cpp
*/

#include <iostream>
#include "Config.hpp"
#include "IndieStudio.hpp"

// Software beau mais 15fps avec la map
// Opengl 30 fps mais pas de lumière
// Burnings video comme opengl mais 10fps
// direct 3d8 segv on load image/button
// direct 3d9 same
// count same
// null bah ya r
IndieStudio::IndieStudio()
    : _eventReceiver(), _settings(true),
    _device(irr::video::EDT_OPENGL, WINDOW_FORMAT, 16, false, false, false,
        &_eventReceiver), _audio(_settings), _sceneType(DEFAULT_SCENE), _scene(
        SceneFactory::createScene(_sceneType, _device, _eventReceiver,
            _settings, _audio))
{
}

void IndieStudio::loop()
{
    auto startDisplay = std::chrono::high_resolution_clock::now();
    auto startUpdate = std::chrono::high_resolution_clock::now();

    while (_sceneType != SCENE_NONE && _device->run()) {
        display(startDisplay);
        update(startUpdate);
    }
}

bool IndieStudio::display(Chrono &chrono)
{
    auto diffDisplay = std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - chrono).count();
    if (diffDisplay < (1.0 / 30.0) * 1000.0)
        return false;
    chrono = std::chrono::high_resolution_clock::now();
    try {
        _device.driver()->beginScene(true, true,
            irr::video::SColor(255, 158, 237, 255));
        _scene->display(diffDisplay);
        _device.driver()->endScene();
    } catch (...) {
        std::cerr << "ERROR Throw in scene display" << std::endl;
    }
    return true;
}

bool IndieStudio::update(Chrono &chrono)
{
    auto diffDisplay = std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - chrono).count();
    if (diffDisplay < (1.0 / 5.0) * 1000.0)
        return false;
    try {
        auto change = _scene->update();
        if (change.first)
            changeScene(change.second);
    } catch (...) {
        std::cerr << "ERROR Throw in scene update" << std::endl;
    }
    return true;
}

void IndieStudio::changeScene(SceneType type)
{
    #ifdef DEBUG
    std::cout << "INFO  Changing scene from " << _sceneType << " to " << type
        << std::endl;
    #endif

    if (type != SCENE_NONE) {
        delete _scene.release();
        _scene.reset(
            SceneFactory::createScene(type, _device, _eventReceiver, _settings,
                _audio));
        _eventReceiver.reset();
        if (!_scene)
            _sceneType = SCENE_NONE;
    }
    _sceneType = type;
}
