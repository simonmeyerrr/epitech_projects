/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Map.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_MAP_HPP
#define OOP_INDIE_STUDIO_2018_MAP_HPP

#include <tuple>
#include <deque>
#include <vector>
#include "Structures.hpp"

class Map {

public:
    Map();
    Map(const Map &copy);
    std::vector<std::vector<BlockType>> getMap() const;
    Map &operator =(const Map &);
    void generator(Block *, MapType);

private:
    void genMapStarterPack();
    void classicMap();
    void complexeMap();
    bool tryToDigUp(const std::tuple<int, int> &) const;
    bool tryToDigDown(const std::tuple<int, int> &) const;
    bool tryToDigLeft(const std::tuple<int, int> &) const;
    bool tryToDigRight(const std::tuple<int, int> &) const;

    void digUp(std::deque<std::tuple<int, int>> &);
    void digDown(std::deque<std::tuple<int, int>> &);
    void digLeft(std::deque<std::tuple<int, int>> &);
    void digRight(std::deque<std::tuple<int, int>> &);

    std::vector<std::vector<BlockType>> _map;
};

#endif /* OOP_INDIE_STUDIO_2018_MAP_HPP */
