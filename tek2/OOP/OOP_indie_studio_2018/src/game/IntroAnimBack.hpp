/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IntroAnimBack.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_INTROANIMBACK_HPP
#define OOP_INDIE_STUDIO_2018_INTROANIMBACK_HPP

#include <chrono>
#include "Structures.hpp"
#include "display/DisplayDecorAnim.hpp"
#include "display/DisplayPlayerAnim.hpp"


class IntroAnimBack {

public:
    ~IntroAnimBack();
    IntroAnimBack(IrrlichtDevice &device, Audio &audio);
    void update();

private:
    void begin();
    void player1Die();
    void stopParticles();
    void player2Move();
    irr::scene::IParticleSystemSceneNode *laser();

    DisplayDecorAnim _decor;
    DisplayPlayerAnim _player[2];
    float _player1Posx;
    float _player2Posx;
    std::size_t _state;
    std::chrono::high_resolution_clock::time_point _time;
    IrrlichtDevice &_device;
    irr::scene::IParticleSystemSceneNode *_particle;
    Audio &_audio;
};

#endif /* OOP_INDIE_STUDIO_2018_INTROANIMBACK_HPP */
