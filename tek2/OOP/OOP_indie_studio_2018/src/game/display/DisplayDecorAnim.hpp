/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayDecorAnim.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_DISPLAYDECORANIM_HPP
#define OOP_INDIE_STUDIO_2018_DISPLAYDECORANIM_HPP

#include "Structures.hpp"
#include "../../irrlicht/IrrlichtDevice.hpp"

class DisplayDecorAnim {
public:
    ~DisplayDecorAnim() = default;
    explicit DisplayDecorAnim(IrrlichtDevice &device);

private:
    IrrlichtDevice &_device;
    irr::scene::ICameraSceneNode *_cam;
};


#endif /* OOP_INDIE_STUDIO_2018_DISPLAYDECORANIM_HPP */
