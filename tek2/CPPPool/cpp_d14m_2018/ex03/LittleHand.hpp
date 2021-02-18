/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** LittleHand.hpp
*/

#ifndef CPP_D14M_2018_LITTLEHAND_HPP_
# define CPP_D14M_2018_LITTLEHAND_HPP_

# include "FruitBox.hpp"
# include "Coconut.hpp"
# include "Mixer.hpp"

class LittleHand {
public:
    LittleHand() = default;
    ~LittleHand() = default;

    static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
        FruitBox &bananas, FruitBox &limes);

    static FruitBox *const *organizeCoconut(Coconut const *const *coconuts);

    static void plugMixer(MixerBase &mixer);
};

#endif /* CPP_D14M_2018_LITTLEHAND_HPP_ */
