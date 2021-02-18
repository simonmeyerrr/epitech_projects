/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** Mixer.hpp
*/

#ifndef CPP_D14M_2018_MIXER_HPP_
# define CPP_D14M_2018_MIXER_HPP_

#include "MixerBase.hpp"

class Mixer : public MixerBase {
public:
    Mixer();
    ~Mixer() = default;

    void plugMe();
};

#endif /* CPP_D14M_2018_MIXER_HPP_ */
