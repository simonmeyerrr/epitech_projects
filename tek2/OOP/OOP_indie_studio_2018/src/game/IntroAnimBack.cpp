/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IntroAnimBack.cpp
*/

#include <iostream>
#include "IntroAnimBack.hpp"
#include "Consts.hpp"

IntroAnimBack::~IntroAnimBack()
{
}

IntroAnimBack::IntroAnimBack(IrrlichtDevice &device, Audio &audio)
    : _decor(DisplayDecorAnim(device)), _player{{device, 0}, {device, 1}},
    _player1Posx((float)(MAP_WIDTH * BLOCK_SIZE)), _player2Posx(-5), _state(0),
    _time(std::chrono::high_resolution_clock::now()), _device(device),
    _particle(nullptr), _audio(audio)
{
    _player[0].setTexture(LAMA_BLACK);
    _player[1].setTexture(LAMA_WHITE);
    _player[0].setPosition(_player1Posx, 0, 5);
    _player[1].setPosition(_player2Posx, 0, 6);
    _player[1].setRotation(DIR_RIGHT);
}

void IntroAnimBack::update()
{

    switch (_state) {
    case 0:
        begin();
        break;
    case 1:
        player1Die();
        break;
    case 2:
        stopParticles();
        break;
    case 3:
        player2Move();
        break;
    default:
        return;
    }
}

void IntroAnimBack::begin()
{
    if (_player1Posx < (float)(MAP_WIDTH * BLOCK_SIZE) / 2) {
        ++_state;
        return;
    }
    _player1Posx -= 0.00002;
    _player[0].setPosition(_player1Posx, 0, 5);
}

void IntroAnimBack::player1Die()
{
    ++_state;
    _player[0].die();
    _particle = laser();
    _audio.playSound(SOUND_LASER);
    _audio.playSound(SOUND_DEATH);
    _time = std::chrono::high_resolution_clock::now();
}

void IntroAnimBack::stopParticles()
{
    auto wait = std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - _time).count();
    if (wait < 1000.0)
        return;
    _particle->remove();
    ++_state;
}

void IntroAnimBack::player2Move()
{
    if (_player2Posx > (float)(MAP_WIDTH * BLOCK_SIZE) / 2 + 1) {
        ++_state;
        _player[1].setRotation(DIR_DOWN);
        _audio.playSound(SOUND_VICTORY);
        return;
    }
    _player2Posx += 0.00002;
    _player[1].setPosition(_player2Posx, 0, 6);
}

irr::scene::IParticleSystemSceneNode *IntroAnimBack::laser()
{
    auto particle = _device.smgr()->addParticleSystemSceneNode(false);
    auto emitter = particle->createBoxEmitter(
        irr::core::aabbox3d<irr::f32>(0, 0, -0.5 * BLOCK_SIZE,
            MAP_HEIGHT * BLOCK_SIZE, 1 * BLOCK_SIZE, 0.5 * BLOCK_SIZE), // pos box
        irr::core::vector3df(0.0f, 0.0f, 0.0f), // direction
        1000, 5000, // min max part/sec
        irr::video::SColor(0, 255, 255, 255), // darkest color
        irr::video::SColor(0, 255, 255, 255), // lightest color
        300, 600, // life min max in mili
        0, // angle d'ecart
        irr::core::dimension2df(0.3f, 0.3f), // taille min
        irr::core::dimension2df(0.5f, 0.5f) // taille max
    );
    particle->setEmitter(emitter);
    particle->setPosition(
        irr::core::vector3df(0, 0, 5));
    particle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    particle->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    irr::scene::IParticleAffector *paf = particle->createFadeOutParticleAffector();
    particle->addAffector(paf); // same goes for the affector
    particle->setMaterialTexture(0, _device->getVideoDriver()->getTexture(
        ASSETS_PATH_STR "textures/fire.bmp"));
    particle->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    paf->drop();
    return particle;
}
