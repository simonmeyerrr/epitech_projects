#ifndef CPP_RTYPE_2019_LOWMONSTERS_HPP
#define CPP_RTYPE_2019_LOWMONSTERS_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../IGameObject.hpp"
#include "../../../../../../Config.hpp"

class LowMonsters : public IGameObject
{
public:
    ~LowMonsters()  = default;
    LowMonsters();

    void render(sf::RenderWindow &, sf::Vector2f) override ;
    void update() override ;
private:
    sf::Texture _textures;
    sf::Sprite _sprites;
    sf::IntRect _rect;
};


#endif //CPP_RTYPE_2019_LOWMONSTERS_HPP
