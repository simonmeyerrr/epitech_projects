    #include <iostream>
#include <utility>
#include "Button.hpp"
#include "../../../Config.hpp"

Button::Button(int id, sf::Vector2f pos, const std::string& name, CallbackPress cbPress)
    : AComponent(id), _font(), _text(), _pos(pos), _size(name.size() * 18.f, 50.f),
    _rect(), _cbPress(std::move(cbPress)), _pressed(false), _timer()
{
    _font.loadFromFile(ASSETS_PATH_STR"coolvetica.ttf");

    _text.setFont(_font);
    _text.setString(name.c_str());
    _text.setCharacterSize(36);
    _text.setFillColor(sf::Color(255, 255, 255));
    _text.setPosition(sf::Vector2f(_pos.x + 24, _pos.y));

    _rect.setOutlineThickness(5.f);
    _rect.setOutlineColor(sf::Color(0, 0, 0));
    _rect.setFillColor(sf::Color(55, 55, 55));
    _rect.setPosition(_pos);
    _rect.setSize(_size);
}

void Button::render(sf::RenderWindow &window)
{
    window.draw(_rect);
    window.draw(_text);
}

void Button::update()
{
    if (_pressed) {
        auto elapsed = _timer.getElapsedTime();
        if (elapsed.asMicroseconds() / 1000000.0 > 0.5) {
            _pressed = false;
            _rect.setFillColor(sf::Color(55, 55, 55));
        }
    }
}

void Button::manageEvent(const sf::Event &event, sf::RenderWindow &win)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (event.mouseButton.x >= _pos.x && event.mouseButton.y >= _pos.y &&
            event.mouseButton.x <= _pos.x + _size.x && event.mouseButton.y <= _pos.y + _size.y) {
            _cbPress();
            _rect.setFillColor(sf::Color(155, 155, 155));
            _timer.restart();
            _pressed = true;
        }
    }
}

