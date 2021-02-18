/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayMap.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_DISPLAYMAP_HPP
# define OOP_INDIE_STUDIO_2018_DISPLAYMAP_HPP

#include "Structures.hpp"
#include "../../audio/Audio.hpp"
#include "../../irrlicht/IrrlichtDevice.hpp"

class DisplayMap {
public:
    ~DisplayMap() = default;
    explicit DisplayMap(IrrlichtDevice &device);
    void display(const GameStats *game, Audio &audio);

private:
    irr::scene::ISceneNode *getBlockModel(BlockType type);
    irr::scene::ISceneNode *copyBlockModel(BlockType type, int pos);
    irr::scene::ISceneNode *getBonusModel(BonusType type);
    irr::scene::ISceneNode *copyBonusModel(BonusType type, int pos);
    irr::scene::IParticleSystemSceneNode *getParticle(int pos);
    irr::scene::ISceneNode *getModel(const std::string &model,
        const std::string &text);
    irr::scene::ISceneNode *copyModel(irr::scene::ISceneNode *node, int pos);

    IrrlichtDevice &_device;

    std::pair<BlockType, irr::scene::ISceneNode *> _blocks[MAP_WIDTH * MAP_HEIGHT];
    std::pair<BonusType, irr::scene::ISceneNode *> _bonuses[MAP_WIDTH * MAP_HEIGHT];
    irr::scene::ISceneNode *_bombs[MAP_WIDTH * MAP_HEIGHT];
    irr::scene::ISceneNode *_explosions[MAP_WIDTH * MAP_HEIGHT];

    irr::scene::ISceneNode *_sand;
    irr::scene::ISceneNode *_bamboo;
    irr::scene::ISceneNode *_rock;
    irr::scene::ISceneNode *_bonus_speed;
    irr::scene::ISceneNode *_bonus_max_bomb;
    irr::scene::ISceneNode *_bonus_power_bomb;
    irr::scene::ISceneNode *_bonus_laser;
    irr::scene::ISceneNode *_bomb;
};

#endif /*OOP_INDIE_STUDIO_2018_DISPLAYMAP_HPP*/
