/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayGame.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_DISPLAYGAME_HPP
#define OOP_INDIE_STUDIO_2018_DISPLAYGAME_HPP

#include "Structures.hpp"
#include "../../irrlicht/IrrlichtDevice.hpp"
#include "../../audio/Audio.hpp"
#include "DisplayDecor.hpp"
#include "DisplayMap.hpp"
#include "DisplayPlayer.hpp"
#include "DisplayOverlay.hpp"

class DisplayGame {
public:
    ~DisplayGame() = default;

    DisplayGame(IrrlichtDevice &device, Audio &audio);
    void display(const GameStats *game);

private:
    IrrlichtDevice &_device;
    Audio &_audio;

    DisplayDecor _displayDecor;
    DisplayMap _displayMap;
    DisplayPlayer _displayPlayer[PLAYER_NUMBER];
    DisplayOverlay _displayOverlay[PLAYER_NUMBER];
};

#endif /* OOP_INDIE_STUDIO_2018_DISPLAYGAME_HPP */
