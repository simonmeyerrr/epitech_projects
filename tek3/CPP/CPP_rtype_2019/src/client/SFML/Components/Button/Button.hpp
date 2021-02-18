#ifndef CPP_RTYPE_2019_BUTTON_HPP
#define CPP_RTYPE_2019_BUTTON_HPP

#include <string>
#include <functional>
#include "../AComponent.hpp"

class Button : public AComponent {
public:
    using CallbackPress = std::function<void ()>;

    ~Button() override = default;
    Button(int id, sf::Vector2f pos, const std::string& name, CallbackPress cbPress);

    void render(sf::RenderWindow &) override;
    void update() override;
    void manageEvent(const sf::Event &, sf::RenderWindow &) override;

private:
    sf::Font _font;
    sf::Text _text;
    sf::Vector2f _pos;
    sf::Vector2f _size;
    sf::RectangleShape _rect;
    CallbackPress _cbPress;
    bool _pressed;
    sf::Clock _timer;
};

#endif //CPP_RTYPE_2019_BUTTON_HPP
