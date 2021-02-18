/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayDecor.cpp
*/

#include "Consts.hpp"
#include "DisplayDecor.hpp"

DisplayDecor::DisplayDecor(IrrlichtDevice &device)
    : _device(device), _cam(nullptr), _podium(nullptr), _fix(false), _end(false)
{
    auto mesh = _device.smgr()->getMesh(MapModel.c_str());
    if (!mesh)
        throw;
    auto texture = _device.driver()->getTexture(MapSkin.c_str());
    if (!texture)
        throw;
    int y = 0;
    for (int x = 0; x < 3 && y < 3; x++) {
        auto map = _device.smgr()->addMeshSceneNode(mesh);
        if (!map)
            throw;
        map->setMaterialTexture(0, texture);
        map->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
        map->setRotation({0, (std::rand() % 4) * 90.f, 0});
        map->setScale({30, 30, 30});
        map->setPosition({((x - 1) * 50 + 5) * BLOCK_SIZE, -1 * BLOCK_SIZE,
            ((y - 1) * 50 + 10) * BLOCK_SIZE});
        if (x == 2) {
            y++;
            x = -1;
        }
    }
    mesh = _device.smgr()->getMesh(PodiumModel.c_str());
    if (!mesh)
        throw;
    texture = _device.driver()->getTexture(PodiumSkin.c_str());
    if (!texture)
        throw;
    _podium = _device.smgr()->addMeshSceneNode(mesh);
    if (!_podium)
        throw;
    _podium->setMaterialTexture(0, texture);
    _podium->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    _podium->setScale({3, 3, 3});
    _podium->setRotation({0, 90, 0});
    _podium->setPosition({(MAP_WIDTH / 2) * BLOCK_SIZE, 0, (MAP_HEIGHT + 5) * BLOCK_SIZE});
    _podium->setVisible(false);
    _cam = _device.smgr()->addCameraSceneNode(nullptr,
        irr::core::vector3df((MAP_WIDTH * BLOCK_SIZE) / 2,
            (MAP_HEIGHT * BLOCK_SIZE), 0),
        irr::core::vector3df((MAP_WIDTH * BLOCK_SIZE) / 2, 0,
            (MAP_HEIGHT * BLOCK_SIZE) / 2));
    auto anim = _device.smgr()->createFlyCircleAnimator(
        {(MAP_WIDTH * BLOCK_SIZE) / 2, (MAP_HEIGHT * BLOCK_SIZE),
            (MAP_HEIGHT * BLOCK_SIZE) / 2}, MAP_WIDTH * BLOCK_SIZE * 0.8,
        0.0002f);
    _cam->addAnimator(anim);
}

void DisplayDecor::display(const GameStats *game, Audio &audio)
{
    if (game && game->started && !_fix) {
        _cam->removeAnimators();
        _cam->setPosition({(MAP_WIDTH * BLOCK_SIZE) / 2, (MAP_HEIGHT * BLOCK_SIZE), 0 });
        _fix = true;
    } else if (game && game->end && !_end) {
        _end = true;
        audio.playSound(SOUND_VICTORY);
        _podium->setVisible(true);
        auto anim = _device.smgr()->createFlyCircleAnimator(
            {(MAP_WIDTH / 2) * BLOCK_SIZE, BLOCK_SIZE * 8, (MAP_HEIGHT + 5) * BLOCK_SIZE}, 7 * BLOCK_SIZE,
            0.0002f);
        _cam->setTarget({(MAP_WIDTH / 2) * BLOCK_SIZE, 3 * BLOCK_SIZE, (MAP_HEIGHT + 5) * BLOCK_SIZE});
        _cam->addAnimator(anim);
    }
}