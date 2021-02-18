/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Audio.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_AUDIO_HPP
#define OOP_INDIE_STUDIO_2018_AUDIO_HPP

#include <SFML/Audio.hpp>
#include <map>
#include <deque>
#include "Enums.hpp"
#include "../Settings.hpp"

class Audio {
public:
    // Ctor
    ~Audio() = default;
    explicit Audio(const Settings &settings);

    // Member functions
    void playSound(Sounds whatSound);
    void playMusic(Musics whatMusic);
    void setGeneralVolume(int vol);
    void setSoundVolume(int vol);
    void setMusicVolume(int vol);

private:
    // Properties
    int _generalVolume;
    int _soundVolume;
    int _musicVolume;
    std::deque<sf::SoundBuffer> _buffers;
    std::map<Sounds, std::deque<std::unique_ptr<sf::Sound>>> _sounds;
    std::map<Musics, std::unique_ptr<sf::Music>> _musics;
};

#endif //OOP_INDIE_STUDIO_2018_AUDIO_HPP
