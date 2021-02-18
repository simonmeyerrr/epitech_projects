/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayDecorAnim.cpp
*/

#include "Consts.hpp"
#include "DisplayDecorAnim.hpp"

DisplayDecorAnim::DisplayDecorAnim(IrrlichtDevice &device)
    : _device(device)
{
    auto meshe = _device.smgr()->getMesh(MapModel.c_str());
    if (!meshe)
        throw;
    auto texture = _device.driver()->getTexture(MapSkin.c_str());
    if (!texture)
        throw;
    int y = 0;
    for (int x = 0; x < 3 && y < 3; x++) {
        auto map = _device.smgr()->addMeshSceneNode(meshe);
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
    _cam = _device.smgr()->addCameraSceneNode(nullptr,
        irr::core::vector3df((MAP_WIDTH * BLOCK_SIZE) / 2,
            (4 * BLOCK_SIZE), (-4 * BLOCK_SIZE)),
        irr::core::vector3df((MAP_WIDTH * BLOCK_SIZE) / 2, 0, (MAP_HEIGHT * BLOCK_SIZE) / 2));

}
