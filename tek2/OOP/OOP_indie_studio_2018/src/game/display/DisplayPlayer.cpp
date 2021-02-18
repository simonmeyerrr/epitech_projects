/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayPlayer.cpp
*/

#include "Consts.hpp"
#include "DisplayPlayer.hpp"

DisplayPlayer::DisplayPlayer(IrrlichtDevice &device, int nb)
    : _device(device), _nb(nb), _texture(nullptr), _model(nullptr),
    _particle(nullptr), _alive(true), _end(false)
{
    auto mesh = _device.smgr()->getMesh(LamasticotModel.c_str());
    if (!mesh)
        throw;
    _model = _device.smgr()->addAnimatedMeshSceneNode(mesh);
    if (!_model)
        throw;
    _model->setVisible(false);
    _model->setFrameLoop(0, 15);
    _model->setAnimationSpeed(30);
    _model->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
}

void DisplayPlayer::display(const GameStats *game, Audio &audio)
{
    if (!game || !game->players[_nb].exist)
        return;
    if (!_texture)
        setTexture(game->players[_nb].skin);
    if (game->end) {
        displayEnd(game);
        return;
    }
    _model->setVisible(true);
    setPosition(game->players[_nb]);
    if (game->players[_nb].alive && game->players[_nb].bonus_laser && !_particle)
        addLaserParticle();
    if (_particle && (!game->players[_nb].alive || !game->players[_nb].bonus_laser)) {
        if (game->players[_nb].alive)
            audio.playSound(SOUND_LASER);
        _particle->remove();
        _particle = nullptr;
    }
    if (!game->players[_nb].alive && _alive) {
        _model->setFrameLoop(20, 45);
        _model->setLoopMode(false);
        _alive = false;
        audio.playSound(SOUND_DEATH);
    } else if (game->players[_nb].alive && !_alive) {
        _model->setFrameLoop(0, 15);
        _model->setLoopMode(true);
        _alive = true;
    }
}

void DisplayPlayer::setTexture(PlayerSkin skin)
{
    _texture = _device->getVideoDriver()->getTexture(
        PlayerSkinPath.at(skin).c_str());
    if (!_texture)
        throw;
    _model->setMaterialTexture(0, _texture);
}

void DisplayPlayer::setPosition(const PlayerStats &player)
{
    float x = player.pos.x * ((100 - player.move_percent) / 100) +
        player.next_pos.x * (player.move_percent / 100);
    float y = player.pos.y * ((100 - player.move_percent) / 100) +
        player.next_pos.y * (player.move_percent / 100);
    _model->setPosition({x * BLOCK_SIZE, 0, (MAP_HEIGHT - y) * BLOCK_SIZE});
    if (_particle)
        _particle->setPosition(
            {x * BLOCK_SIZE, 0, (MAP_HEIGHT - y) * BLOCK_SIZE});
    _model->setRotation({0, player.dir + 90.f, 0});
}

void DisplayPlayer::addLaserParticle()
{
    _particle = _device.smgr()->addParticleSystemSceneNode(false);
    auto emitter = _particle->createBoxEmitter(
        {-0.5 * BLOCK_SIZE, 0, -0.5 * BLOCK_SIZE, 0.5 * BLOCK_SIZE, 1,
            0.5 * BLOCK_SIZE}, // pos box
        {0, 0.05, 0}, // direction
        40, 80, // min max part/sec
        {0, 100, 100, 100}, // darkest color
        {0, 255, 255, 255}, // lighter color
        80, 150, // life min max in mili
        0, // angle d'ecart
        {0.3, 0.3}, // taille min
        {0.5, 0.5} // taille max
    );
    _particle->setEmitter(emitter);
    _particle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _particle->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    _particle->setMaterialTexture(0, _device->getVideoDriver()->getTexture(ASSETS_PATH_STR "textures/powerup.bmp"));
    _particle->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

void DisplayPlayer::displayEnd(const GameStats *game)
{
    if (!game || !game->players[_nb].exist || _end)
        return;
    _end = true;
    _model->setVisible(true);
    if (_particle) {
        _particle->remove();
        _particle = nullptr;
    }
    _model->setFrameLoop(0, 15);
    _model->setLoopMode(true);
    int player_before = 0;
    for (int i = 0; i < _nb; i++) {
        if (game->players[i].rank == game->players[_nb].rank)
            player_before++;
    }
    irr::core::vector3df pos = {0, 0, 0};
    if (game->players[_nb].rank == 1)
        pos = {(MAP_WIDTH / 2) * BLOCK_SIZE + 1, 4.5, (MAP_HEIGHT + 5) * BLOCK_SIZE - 1.4};
    else if (game->players[_nb].rank == 2)
        pos = {(MAP_WIDTH / 2) * BLOCK_SIZE - 4.5, 2.5, (MAP_HEIGHT + 5) * BLOCK_SIZE - 1.4};
    else if (game->players[_nb].rank == 3)
        pos = {(MAP_WIDTH / 2) * BLOCK_SIZE + 6, -0.1, (MAP_HEIGHT + 5) * BLOCK_SIZE - 1.4};
    else
        pos = {(MAP_WIDTH / 2) * BLOCK_SIZE, -0.5, (MAP_HEIGHT + 9) * BLOCK_SIZE};
    pos = {pos.X - 2 * player_before, pos.Y, pos.Z + 1 * player_before};
    _model->setPosition(pos);
    _model->setRotation({0, -90, 0});
}