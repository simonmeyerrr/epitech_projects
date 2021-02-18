/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IScene.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_ASCENE_HPP
    #define OOP_INDIE_STUDIO_2018_ASCENE_HPP

#include "../irrlicht/IrrlichtDevice.hpp"
#include "../irrlicht/MyEventReceiver.hpp"
#include "../irrlicht/ResponsiveGui.hpp"
#include "../Settings.hpp"
#include "IScene.hpp"
#include "../audio/Audio.hpp"

class AScene : public IScene{
public:
    ~AScene() override = default;
    AScene(IrrlichtDevice &device, MyEventReceiver &event, Settings &settings,
           Audio &audio)
        : _device(device), _eventReceiver(event), _settings(settings),
        _audio(audio), _responsiveGui(device)
    {}

protected:
    IrrlichtDevice &_device;
    MyEventReceiver &_eventReceiver;
    Settings &_settings;
    Audio &_audio;
    ResponsiveGui _responsiveGui;
};

#endif /*OOP_INDIE_STUDIO_2018_ASCENE_HPP*/
