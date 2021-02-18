//
// Created by hugo on 11/25/19.
//

#ifndef CPP_RTYPE_2019_BACKGROUND_HPP
#define CPP_RTYPE_2019_BACKGROUND_HPP

#include <cstdlib>
#include "../AComponent.hpp"
#include "../../../Config.hpp"

#define MAX_STARS 80

class Background : public AComponent
{
public:
    ~Background() override = default;
    Background();

    void render(sf::RenderWindow &) override;
    void update() override;
    void manageEvent(const sf::Event &event, sf::RenderWindow &win) override;

private:

    struct Infos
    {
        sf::Vector2f pos;
        sf::Vector2f size;
        float rotation;
        float speed;
    };


    sf::Texture _texture;
    sf::Clock _time;
    Infos _stars[MAX_STARS];
    sf::Sprite _sprite;

};


#endif //CPP_RTYPE_2019_BACKGROUND_HPP
