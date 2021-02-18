/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Settings.hpp
*/

#ifndef CPP_RUSH3_2018_SETTINGS_HPP_
# define CPP_RUSH3_2018_SETTINGS_HPP_

# include "Types.hpp"
# include <string>

class Settings {
public:
    ~Settings();
    Settings(Types::DisplayMode);
    Settings(const Settings &);
    Settings &operator=(const Settings &);

    Types::DisplayMode getDisplayMode() const;
    void setDisplayMode(Types::DisplayMode);

    bool isLaunched() const;
    void closeProg();

private:
    Types::DisplayMode _displayMode;
    bool _launched;
};
#endif /* CPP_RUSH3_2018_SETTINGS_HPP_ */
