#include <iostream>
#include <utility>
#include "InputField.hpp"

InputField::InputField(int id, sf::Vector2f pos,
        CallbackInput cbInput, int &selected, const std::string &placeHolder, const std::string &defaultName)
        : AComponent(id), _selected(selected), _font(), _pos(pos), _size(200, 50), _rect(),
        _textInput(), _placeHolder(), _userInput(),
        _cbInput(std::move(cbInput))
{
    _font.loadFromFile(ASSETS_PATH_STR "coolvetica.ttf");

    _textInput.setFont(_font);
    _textInput.setCharacterSize(36);
    _textInput.setFillColor(sf::Color(255, 255, 255));
    _textInput.setPosition(sf::Vector2f(_pos.x + 24, _pos.y));
    if (!defaultName.empty())
        _userInput = defaultName;
    else {
        _placeHolder.setString(placeHolder);
        _placeHolder.setFont(_font);
        _placeHolder.setCharacterSize(36);
        _placeHolder.setFillColor(sf::Color(180, 180, 180));
        _placeHolder.setPosition(sf::Vector2f(_pos.x + 24, _pos.y));
    }

    _rect.setOutlineThickness(5.f);
    _rect.setOutlineColor(sf::Color(0, 0, 0));
    _rect.setFillColor(sf::Color(55, 55, 55));
    _rect.setPosition(_pos);
    _rect.setSize(_size);
}


void InputField::update()
{
    _textInput.setString(_userInput.c_str());
    if (_selected == _id)
        _rect.setFillColor(sf::Color(155, 155, 155));
    else
        _rect.setFillColor(sf::Color(55, 55, 55));
}

void InputField::render(sf::RenderWindow &window)
{
    window.draw(_rect);
    if (_userInput.empty())
        window.draw(_placeHolder);
    else
        window.draw(_textInput);
}

void InputField::manageEvent(const sf::Event &event, sf::RenderWindow &win)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (event.mouseButton.x >= _pos.x && event.mouseButton.y >= _pos.y &&
            event.mouseButton.x <= _pos.x + _size.x && event.mouseButton.y <= _pos.y + _size.y) {
            _selected = _id;
        }
    }
    if (event.type == sf::Event::KeyPressed && _selected == _id && event.key.code == sf::Keyboard::BackSpace && !_userInput.empty()) {
        _userInput.pop_back();
        _cbInput(_userInput);
    }
    if (_selected == _id && event.type == sf::Event::TextEntered) {
        if (event.text.unicode <= 126 && event.text.unicode >= 33 && _userInput.size() < 15) {
            _userInput += static_cast<char>(event.text.unicode);
            _cbInput(_userInput);
        }
    }
}
