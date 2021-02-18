/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayPlayerAnim.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_DISPLAYPLAYERANIM_HPP
#define OOP_INDIE_STUDIO_2018_DISPLAYPLAYERANIM_HPP

#include "Consts.hpp"
#include "../../irrlicht/IrrlichtDevice.hpp"
#include "../../audio/Audio.hpp"

class DisplayPlayerAnim {

public:
    ~DisplayPlayerAnim() = default;
    DisplayPlayerAnim(IrrlichtDevice &device, int nb);
    void setTexture(PlayerSkin skin);
    void setPosition(float, float, float);
    void setRotation(Direction);
    void die();


private:
    IrrlichtDevice &_device;
    int _nb;
    irr::video::ITexture *_texture;
    irr::scene::IAnimatedMeshSceneNode *_model;
    bool _alive;
};

#endif /*OOP_INDIE_STUDIO_2018_DISPLAYPLAYERANIM_HPP*/
