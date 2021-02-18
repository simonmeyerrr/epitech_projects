/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IScene.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_ISCENE_HPP
    #define OOP_INDIE_STUDIO_2018_ISCENE_HPP

#include <memory>
#include "SceneType.hpp"

class IScene {
public:
    virtual ~IScene() = default;

    virtual ChangeScene update() = 0;
    virtual void display(double diff) = 0;
};

using ScenePtr = std::unique_ptr<IScene>;

#endif /* OOP_INDIE_STUDIO_2018_ISCENE_HPP */
