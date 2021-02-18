/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Audio.cpp
*/

#include <iostream>
#include "Audio.hpp"
#include "Config.hpp"
#include "Consts.hpp"

Audio::Audio(const Settings &settings)
    : _generalVolume(settings.settings.general_volume),
    _soundVolume(settings.settings.sfx_volume),
    _musicVolume(settings.settings.music_volume),
    _buffers(), _sounds(), _musics()
{
    // Load every sounds
    for (const auto &sound: SoundsPath) {
        auto &tab = _sounds.emplace(sound.first, std::deque<std::unique_ptr<sf::Sound>>()).first->second;
        for (const auto &path: sound.second) {
            _buffers.emplace_front();
            tab.emplace_front(new sf::Sound());
            if (!_buffers.begin()->loadFromFile(path)) {
                _buffers.erase(_buffers.begin());
                tab.erase(tab.begin());
            } else {
                (*tab.begin())->setBuffer(*_buffers.begin());
            }
        }
    }
    // Load every musics
    for (const auto &music: MusicsPath) {
        _musics.emplace(music.first, new sf::Music());
        if (!_musics.at(music.first)->openFromFile(music.second))
            _musics.erase(music.first);
        else
            _musics.at(music.first)->setLoop(true);
    }
    setGeneralVolume(_generalVolume);
}

void Audio::playSound(Sounds whatSound)
{
    try {
        auto &map = _sounds.at(whatSound);
        if (map.size() == 0)
            return;
        unsigned int nb = std::rand() % map.size();
        if (map[nb])
            map[nb]->play();
    } catch (...) {
    }
}

void Audio::playMusic(Musics whatMusic)
{
    try {
        if (_musics.at(whatMusic)->getStatus() == sf::SoundSource::Playing)
            return;
        for (auto &it : _musics)
            it.second->stop();
        _musics.at(whatMusic)->play();
    } catch (...) {
    }
}

void Audio::setGeneralVolume(int vol)
{
    if (vol < 0)
        vol = 0;
    else if (vol > 100)
        vol = 100;
    _generalVolume = vol;
    setSoundVolume(_soundVolume);
    setMusicVolume(_musicVolume);
}

void Audio::setSoundVolume(int vol)
{
    if (vol < 0)
        vol = 0;
    else if (vol > 100)
        vol = 100;
    _soundVolume = vol;
    for (auto &i: _sounds) {
        for (auto &j: i.second) {
            if (j)
                j->setVolume(_soundVolume * (_generalVolume / 100.0));
        }
    }
}

void Audio::setMusicVolume(int vol)
{
    if (vol < 0)
        vol = 0;
    else if (vol > 100)
        vol = 100;
    _musicVolume = vol;
    for (auto &i: _musics) {
        if (i.second)
            i.second->setVolume(_musicVolume * (_generalVolume / 100.0));
    }
}