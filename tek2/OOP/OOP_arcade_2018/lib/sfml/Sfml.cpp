/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Sfml.cpp
*/

#include <memory>
#include <tuple>
#include <string>
#include <iostream>
#include "Sfml.hpp"

void __attribute__((constructor)) ctor()
{
}

void __attribute__((destructor)) dtor()
{
}

extern "C" arcade::IGraphic *init()
{
    return new arcade::Sfml();
}

namespace arcade {
    const std::tuple<int, EventType> events[] = {
        {sf::Keyboard::A, ARCADE_KEY_A}, {sf::Keyboard::B, ARCADE_KEY_B},
        {sf::Keyboard::C, ARCADE_KEY_C}, {sf::Keyboard::D, ARCADE_KEY_D},
        {sf::Keyboard::E, ARCADE_KEY_E}, {sf::Keyboard::F, ARCADE_KEY_F},
        {sf::Keyboard::G, ARCADE_KEY_G}, {sf::Keyboard::H, ARCADE_KEY_H},
        {sf::Keyboard::I, ARCADE_KEY_I}, {sf::Keyboard::J, ARCADE_KEY_J},
        {sf::Keyboard::K, ARCADE_KEY_K}, {sf::Keyboard::L, ARCADE_KEY_L},
        {sf::Keyboard::M, ARCADE_KEY_M}, {sf::Keyboard::N, ARCADE_KEY_N},
        {sf::Keyboard::O, ARCADE_KEY_O}, {sf::Keyboard::P, ARCADE_KEY_P},
        {sf::Keyboard::Q, ARCADE_KEY_Q}, {sf::Keyboard::R, ARCADE_KEY_R},
        {sf::Keyboard::S, ARCADE_KEY_S}, {sf::Keyboard::T, ARCADE_KEY_T},
        {sf::Keyboard::U, ARCADE_KEY_U}, {sf::Keyboard::V, ARCADE_KEY_V},
        {sf::Keyboard::W, ARCADE_KEY_W}, {sf::Keyboard::X, ARCADE_KEY_X},
        {sf::Keyboard::Y, ARCADE_KEY_Y}, {sf::Keyboard::Z, ARCADE_KEY_Z},
        {sf::Keyboard::Num0, ARCADE_KEY_0}, {sf::Keyboard::Num1, ARCADE_KEY_1},
        {sf::Keyboard::Num2, ARCADE_KEY_2}, {sf::Keyboard::Num3, ARCADE_KEY_3},
        {sf::Keyboard::Num4, ARCADE_KEY_4}, {51, ARCADE_KEY_4},
        {sf::Keyboard::Num5, ARCADE_KEY_5}, {sf::Keyboard::Num6, ARCADE_KEY_6},
        {56, ARCADE_KEY_6}, {sf::Keyboard::Num7, ARCADE_KEY_7},
        {sf::Keyboard::Num8, ARCADE_KEY_8}, {sf::Keyboard::Num9, ARCADE_KEY_9},
        {sf::Keyboard::F1, ARCADE_KEY_F1}, {sf::Keyboard::F2, ARCADE_KEY_F2},
        {sf::Keyboard::F3, ARCADE_KEY_F3}, {sf::Keyboard::F4, ARCADE_KEY_F4},
        {sf::Keyboard::F5, ARCADE_KEY_F5}, {sf::Keyboard::F6, ARCADE_KEY_F6},
        {sf::Keyboard::F7, ARCADE_KEY_F7}, {sf::Keyboard::F8, ARCADE_KEY_F8},
        {sf::Keyboard::F9, ARCADE_KEY_F9}, {sf::Keyboard::F10, ARCADE_KEY_F10},
        {sf::Keyboard::F11, ARCADE_KEY_F11},
        {sf::Keyboard::F12, ARCADE_KEY_F12},
        {sf::Keyboard::Left, ARCADE_KEY_LEFT},
        {sf::Keyboard::Right, ARCADE_KEY_RIGHT},
        {sf::Keyboard::Up, ARCADE_KEY_UP},
        {sf::Keyboard::Down, ARCADE_KEY_DOWN},
        {sf::Keyboard::Tab, ARCADE_KEY_TAB},
        {sf::Keyboard::Space, ARCADE_KEY_SPACE},
        {sf::Keyboard::Escape, ARCADE_KEY_ESCAPE},
        {sf::Keyboard::Return, ARCADE_KEY_ENTER},
        {sf::Keyboard::BackSpace, ARCADE_KEY_DELETE}};

    Sfml::~Sfml()
    {
        if (_win.isOpen())
            _win.close();
    }

    Sfml::Sfml()
        : _win(sf::VideoMode(1600, 900, 32), "Arcade",
        sf::Style::Close | sf::Style::Resize), _font()
    {
        if (!_font.loadFromFile("./assets/font.ttf"))
            throw std::exception();
    }

    Event Sfml::getEvent()
    {
        if (!_win.isOpen())
            return (Event(ARCADE_CLOSE_WINDOW));

        sf::Event event;
        while (_win.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                _win.close();
                return (Event(ARCADE_CLOSE_WINDOW));
            }
            if (event.type == sf::Event::EventType::KeyPressed)
                return (manageKeyPressed(event.key.code));
            if (event.type == sf::Event::MouseButtonPressed)
                return (manageMousePressed(event.mouseButton));
        }
        return (Event(ARCADE_NO_EVENT));
    }

    Event Sfml::manageKeyPressed(sf::Keyboard::Key key)
    {
        for (int i = 0; i < 59; i++) {
            if (std::get<0>(events[i]) == key) {
                return (Event(std::get<1>(events[i])));
            }
        }
        return (Event(ARCADE_NO_EVENT));
    }

    Event Sfml::manageMousePressed(sf::Event::MouseButtonEvent mouse)
    {
        if (mouse.button == sf::Mouse::Button::Left)
            return (Event(ARCADE_CLICK_LEFT, mouse.x / 20, mouse.y / 20));
        else if (mouse.button == sf::Mouse::Button::Right)
            return (Event(ARCADE_CLICK_RIGHT, mouse.x / 20, mouse.y / 20));
        else
            return (Event(ARCADE_NO_EVENT));
    }

    void Sfml::clearWindow(Color color)
    {
        if (!_win.isOpen())
            return;
        _win.clear(getColor(color));
    }

    void Sfml::displayWindow()
    {
        if (!_win.isOpen())
            return;
        _win.display();
    }

    void Sfml::printPixel(Vector v, Color color)
    {
        if (!_win.isOpen())
            return;
        sf::Color c = getColor(color);
        sf::VertexArray array(sf::Quads, 4);
        array[0].position = sf::Vector2f(v.x * 20, v.y * 20);
        array[0].color = c;
        array[1].position = sf::Vector2f(v.x * 20, v.y * 20 + 1 * 20);
        array[1].color = c;
        array[2].position = sf::Vector2f(v.x * 20 + 1 * 20, v.y * 20 + 1 * 20);
        array[2].color = c;
        array[3].position = sf::Vector2f(v.x * 20 + 1 * 20, v.y * 20);
        array[3].color = c;
        _win.draw(array);
    }

    void Sfml::printRectangle(Vector pos, Vector size, Color color)
    {
        if (!_win.isOpen())
            return;
        sf::Color c = getColor(color);
        sf::VertexArray array(sf::Quads, 4);
        array[0].position = sf::Vector2f(pos.x * 20, pos.y * 20);
        array[0].color = c;
        array[1].position = sf::Vector2f(pos.x * 20, pos.y * 20 + size.y * 20);
        array[1].color = c;
        array[2].position = sf::Vector2f(pos.x * 20 + size.x * 20,
            pos.y * 20 + size.y * 20);
        array[2].color = c;
        array[3].position = sf::Vector2f(pos.x * 20 + size.x * 20, pos.y * 20);
        array[3].color = c;
        _win.draw(array);
    }

    void Sfml::printText(Vector v, const std::string &str, Color color,
        Color background)
    {
        int width = (str.size() % 2 == 0 ? str.size() / 2 : str.size() / 2 + 1);
        int offset = 0;
        if (!_win.isOpen()) {
            return;
        }
        printRectangle(v, Vector(width, 1), background);
        sf::Text text(str, _font, 21);
        offset = (width * 20 - text.getLocalBounds().width) / 2;
        text.setPosition(sf::Vector2f(v.x * 20 + offset, v.y * 20 - 1));
        text.setFillColor(getColor(color));
        _win.draw(text);
    }

    sf::Color Sfml::getColor(Color color)
    {
        switch (color) {
        case ARCADE_TRANSPARENT:
            return (sf::Color(255, 255, 255, 0));
        case ARCADE_WHITE:
            return (sf::Color(240, 240, 240, 255));
        case ARCADE_BLACK:
            return (sf::Color(50, 50, 50, 255));
        case ARCADE_RED:
            return (sf::Color(255, 81, 0, 255));
        case ARCADE_BLUE:
            return (sf::Color(48, 140, 231, 255));
        case ARCADE_GREEN:
            return (sf::Color(130, 200, 55, 255));
        case ARCADE_YELLOW:
            return (sf::Color(240, 186, 17, 255));
        case ARCADE_MAGENTA:
            return (sf::Color(154, 108, 176, 255));
        case ARCADE_CYAN:
            return (sf::Color(0, 200, 224, 255));
        default:
            return (sf::Color(50, 50, 50, 255));
        }
    }
}

