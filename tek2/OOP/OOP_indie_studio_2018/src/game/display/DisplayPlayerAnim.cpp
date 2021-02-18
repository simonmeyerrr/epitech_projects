/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayPlayerAnim.cpp
*/

#include "DisplayPlayerAnim.hpp"

DisplayPlayerAnim::DisplayPlayerAnim(IrrlichtDevice &device, int nb)
    : _device(device), _nb(nb), _texture(nullptr), _model(nullptr), _alive(true)
{
    auto mesh = _device.smgr()->getMesh(LamasticotModel.c_str());
    if (!mesh)
        throw;
    _model = _device.smgr()->addAnimatedMeshSceneNode(mesh);
    if (!_model)
        throw;
    _model->setVisible(true);
    _model->setFrameLoop(0, 15);
    _model->setAnimationSpeed(30);
    _model->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    _model->setPosition({0, 0, 5});
}

void DisplayPlayerAnim::die()
{
    _model->setFrameLoop(20, 45);
    _model->setLoopMode(false);
    _alive = false;
}

void DisplayPlayerAnim::setTexture(PlayerSkin skin)
{
    _texture = _device->getVideoDriver()->getTexture(
        PlayerSkinPath.at(skin).c_str());
    if (!_texture)
        throw;
    _model->setMaterialTexture(0, _texture);
}

void DisplayPlayerAnim::setPosition(float x, float y, float z)
{
    _model->setPosition({x, y, z});
}

void DisplayPlayerAnim::setRotation(Direction dir)
{
    _model->setRotation({0, dir + 90.f, 0});
}
