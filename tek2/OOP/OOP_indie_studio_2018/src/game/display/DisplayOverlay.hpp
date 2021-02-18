/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** DisplayOverlay.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_DISPLAYOVERLAY_HPP
#define OOP_INDIE_STUDIO_2018_DISPLAYOVERLAY_HPP

#include "Structures.hpp"
#include "../../irrlicht/IrrlichtDevice.hpp"
#include "../../audio/Audio.hpp"

class DisplayOverlay {
public:
    ~DisplayOverlay() = default;
    DisplayOverlay(IrrlichtDevice &device, int nb);
    void display(const GameStats *game, Audio &audio);

private:
    void changeText(const std::string &str, irr::gui::IGUIStaticText *txt);
    void drawText(irr::gui::IGUIStaticText *txt,
        const irr::core::position2di &pos);
    void drawImage(irr::gui::IGUIImage *image,
        const irr::core::position2di &pos);

    IrrlichtDevice &_device;
    int _nb;

    irr::gui::IGUIImage *_back;
    irr::gui::IGUIImage *_connected;
    irr::gui::IGUIImage *_disconnected;
    irr::gui::IGUIStaticText *_player;
    irr::gui::IGUIStaticText *_rank;
    irr::gui::IGUIStaticText *_speed;
    irr::gui::IGUIStaticText *_bombs;
    irr::gui::IGUIStaticText *_bombs_power;
};

#endif /* OOP_INDIE_STUDIO_2018_DISPLAYOVERLAY_HPP */
