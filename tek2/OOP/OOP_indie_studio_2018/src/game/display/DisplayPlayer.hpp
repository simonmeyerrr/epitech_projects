/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayPlayer.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_DISPLAYPLAYER_HPP
# define OOP_INDIE_STUDIO_2018_DISPLAYPLAYER_HPP

#include "Structures.hpp"
#include "../../irrlicht/IrrlichtDevice.hpp"
#include "../../audio/Audio.hpp"

class DisplayPlayer {
public:
    ~DisplayPlayer() = default;
    DisplayPlayer(IrrlichtDevice &device, int nb);
    void display(const GameStats *game, Audio &audio);

private:
    void setTexture(PlayerSkin skin);
    void setPosition(const PlayerStats &player);
    void addLaserParticle();
    void displayEnd(const GameStats *game);

    IrrlichtDevice &_device;
    int _nb;
    irr::video::ITexture *_texture;
    irr::scene::IAnimatedMeshSceneNode *_model;
    irr::scene::IParticleSystemSceneNode *_particle;
    bool _alive;
    bool _end;
};

#endif /* OOP_INDIE_STUDIO_2018_DISPLAYPLAYER_HPP */
