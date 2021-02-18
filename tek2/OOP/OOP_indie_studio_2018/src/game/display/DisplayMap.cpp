/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayMap.cpp
*/

#include "Consts.hpp"
#include "DisplayMap.hpp"
#include <iostream>

DisplayMap::DisplayMap(IrrlichtDevice &device)
    : _device(device), _blocks(), _bombs(), _sand(getBlockModel(BLOCK_NONE)),
    _bamboo(getBlockModel(BLOCK_BREAKABLE)),
    _rock(getBlockModel(BLOCK_UNBREAKABLE)),
    _bonus_speed(getBonusModel(BONUS_SPEED_UP)),
    _bonus_max_bomb(getBonusModel(BONUS_BOMB_MAX)),
    _bonus_power_bomb(getBonusModel(BONUS_BOMB_POWER)),
    _bonus_laser(getBonusModel(BONUS_LASER)),
    _bomb(getModel(BombModel, BombSkin))
{
    _bomb->setRotation({0, 180, 0});
    for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++) {
        _blocks[i].first = BLOCK_NONE;
        _blocks[i].second = copyBlockModel(BLOCK_NONE, i);
        _bonuses[i].first = BONUS_NONE;
        _bonuses[i].second = nullptr;
        _bombs[i] = nullptr;
        _explosions[i] = nullptr;
    }
}

void DisplayMap::display(const GameStats *game, Audio &audio)
{
    for (int i = 0; game && i < MAP_HEIGHT * MAP_WIDTH; i++) {
        if (_blocks[i].first != game->map[i].type) {
            _blocks[i].first = game->map[i].type;
            if (_blocks[i].second)
                _blocks[i].second->remove();
            _blocks[i].second = copyBlockModel(game->map[i].type, i);
        }
        if (_bonuses[i].first != game->map[i].bonus) {
            _bonuses[i].first = game->map[i].bonus;
            if (_bonuses[i].second) {
                _bonuses[i].second->remove();
                audio.playSound(SOUND_BONUS);
            }
            _bonuses[i].second = copyBonusModel(game->map[i].bonus, i);
        }
        if (_bombs[i] && !game->map[i].bomb) {
            _bombs[i]->remove();
            _bombs[i] = nullptr;
            audio.playSound(SOUND_EXPLOSION);
        } else if (!_bombs[i] && game->map[i].bomb) {
            _bombs[i] = copyModel(_bomb, i);
        }
        if (_bombs[i]) {
            _bombs[i]->setScale({
                (float)(1.0 + game->map[i].bomb_percent / 200.0),
                (float)(1.0 + game->map[i].bomb_percent / 200.0),
                (float)(1.0 + game->map[i].bomb_percent / 200.0)});
        }
        if (_explosions[i] && !game->map[i].explosion) {
            _explosions[i]->remove();
            _explosions[i] = nullptr;
        } else if (!_explosions[i] && game->map[i].explosion) {
            _explosions[i] = getParticle(i);
        }
        if (_explosions[i]) {
            _explosions[i]->setScale({
                (float)(1.0 - game->map[i].explosion_percent / 400.0),
                (float)(1.0 - game->map[i].explosion_percent / 200.0),
                (float)(1.0 - game->map[i].explosion_percent / 400.0)
            });
        }
    }
}

irr::scene::ISceneNode *DisplayMap::getBlockModel(BlockType type)
{
    auto infos = BlockModels.at(type);

    return getModel(infos.first, infos.second);
}

irr::scene::ISceneNode *DisplayMap::copyBlockModel(BlockType type, int pos)
{
    switch (type) {
    case BLOCK_NONE:
        return copyModel(_sand, pos);
    case BLOCK_UNBREAKABLE:
        return copyModel(_rock, pos);
    case BLOCK_BREAKABLE:
        return copyModel(_bamboo, pos);
    default:
        throw;
    }
}

irr::scene::ISceneNode *DisplayMap::getBonusModel(BonusType type)
{
    if (type == BONUS_NONE)
        return nullptr;

    return getModel(BonusModel, BonusSkins.at(type));
}

irr::scene::ISceneNode *DisplayMap::copyBonusModel(BonusType type, int pos)
{
    irr::scene::ISceneNode *copy = nullptr;

    switch (type) {
    case BONUS_NONE:
        copy = nullptr;
        break;
    case BONUS_SPEED_UP:
        copy = copyModel(_bonus_speed, pos);
        break;
    case BONUS_BOMB_MAX:
        copy = copyModel(_bonus_max_bomb, pos);
        break;
    case BONUS_BOMB_POWER:
        copy = copyModel(_bonus_power_bomb, pos);
        break;
    case BONUS_LASER:
        copy = copyModel(_bonus_laser, pos);
        break;
    default:
        throw;
    }
    if (copy) {
        auto new_pos = copy->getPosition();
        copy->setRotation({0, 0, 45});
        copy->setPosition({new_pos.X, new_pos.Y + (0.5f * BLOCK_SIZE),
            new_pos.Z});
        auto anim = _device.smgr()->createRotationAnimator({0, 1.0f, 0});
        copy->addAnimator(anim);
    }
    return copy;
}

irr::scene::ISceneNode *DisplayMap::getModel(const std::string &model,
    const std::string &text)
{
    auto node = _device.smgr()->addMeshSceneNode(
        _device.smgr()->getMesh(model.c_str()));
    auto texture = _device.driver()->getTexture(text.c_str());
    if (!node || !texture)
        throw;
    node->setVisible(false);
    node->setMaterialTexture(0, texture);
    node->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    return node;
}

irr::scene::ISceneNode *DisplayMap::copyModel(irr::scene::ISceneNode *node,
    int pos)
{
    auto copy = node->clone(_device.smgr()->getRootSceneNode(), _device.smgr());

    if (!copy)
        throw;
    copy->setVisible(true);
    int x = pos % MAP_WIDTH;
    int y = (pos - x) / MAP_HEIGHT;
    copy->setPosition(
        irr::core::vector3df(x * BLOCK_SIZE, 0, (MAP_HEIGHT - y) * BLOCK_SIZE));
    return copy;
}

irr::scene::IParticleSystemSceneNode *DisplayMap::getParticle(int pos)
{
    auto particle = _device.smgr()->addParticleSystemSceneNode(false);
    auto emitter = particle->createBoxEmitter(
        irr::core::aabbox3d<irr::f32>(-0.5 * BLOCK_SIZE, 0, -0.5 * BLOCK_SIZE, 0.5 * BLOCK_SIZE, 1 * BLOCK_SIZE,
         0.5 * BLOCK_SIZE), // pos box
        irr::core::vector3df(0.0f, 0.0f, 0.0f), // direction
        500, 1000, // min max part/sec
        irr::video::SColor(0, 255, 255, 255), // darkest color
        irr::video::SColor(0, 255, 255, 255), // lightest color
        300, 600, // life min max in mili
        0, // angle d'ecart
        irr::core::dimension2df(0.3f, 0.3f), // taille min
        irr::core::dimension2df(0.5f, 0.5f) // taille max
    );
    particle->setEmitter(emitter);
    int x = pos % MAP_WIDTH;
    int y = (pos - x) / MAP_HEIGHT;
    particle->setPosition(
            irr::core::vector3df(x * BLOCK_SIZE, 0, (MAP_HEIGHT - y) * BLOCK_SIZE));
    particle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    particle->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    irr::scene::IParticleAffector *paf = particle->createFadeOutParticleAffector();
    particle->addAffector(paf); // same goes for the affector
    particle->setMaterialTexture(0, _device->getVideoDriver()->getTexture(ASSETS_PATH_STR "textures/fire.bmp"));
    particle->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    paf->drop();
    return particle;
}