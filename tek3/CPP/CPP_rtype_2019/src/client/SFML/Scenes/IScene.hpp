#ifndef CPP_RTYPE_2019_ISCENE_HPP
#define CPP_RTYPE_2019_ISCENE_HPP

#include <SFML/Graphics.hpp>

class IScene {
public:
    using SceneType = enum {
        SCENE_NONE,
        SCENE_CONNECTING,
        SCENE_CONNECTED,
        SCENE_GAME
    };

    virtual ~IScene() = default;

    virtual void render(sf::RenderWindow &) = 0;
    virtual void update() = 0;
    virtual void manageEvent(const sf::Event &, sf::RenderWindow &) = 0;
    virtual SceneType getType() const = 0;
};

using IScenePtr = std::unique_ptr<IScene>;

#endif //CPP_RTYPE_2019_ISCENE_HPP
