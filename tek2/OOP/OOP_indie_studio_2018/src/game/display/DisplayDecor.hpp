/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayDecor.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_DISPLAYDECOR_HPP
# define OOP_INDIE_STUDIO_2018_DISPLAYDECOR_HPP

#include "Structures.hpp"
#include "../../irrlicht/IrrlichtDevice.hpp"
#include "../../audio/Audio.hpp"

class DisplayDecor {
public:
    ~DisplayDecor() = default;
    explicit DisplayDecor(IrrlichtDevice &device);
    void display(const GameStats *game, Audio &audio);

private:
    IrrlichtDevice &_device;

    irr::scene::ICameraSceneNode *_cam;
    irr::scene::ISceneNode *_podium;
    bool _fix;
    bool _end;
};

#endif /* OOP_INDIE_STUDIO_2018_DISPLAYDECOR_HPP */
