/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorSfml.cpp
*/

#include "Text.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "MonitorSfml.hpp"

MonitorSfml::~MonitorSfml()
{
    delete _win;
}

MonitorSfml::MonitorSfml()
{
    sf::VideoMode mode(1005, 1005, 32);
    _win = new sf::RenderWindow(mode, "Monitor", sf::Style::Close);
}

static sf::Color getMixColor(sf::Color color1, sf::Color color2)
{
    sf::Uint8 r = (color1.r + color2.r) / (sf::Uint8)2;
    sf::Uint8 g = (color1.g + color2.g) / (sf::Uint8)2;
    sf::Uint8 b = (color1.b + color2.b) / (sf::Uint8)2;
    sf::Uint8 a = (color1.a + color2.a) / (sf::Uint8)2;
    sf::Color color(r, g, b, a);
    return (color);
}

static sf::VertexArray getRectangle(sf::Vector2f origin, sf::Vector2f size,
    sf::Color color1, sf::Color color2)
{
    sf::VertexArray array(sf::Quads, 4);
    array[0].position = origin;
    array[0].color = color1;
    array[1].position = sf::Vector2f(origin.x, origin.y + size.y);
    array[1].color = getMixColor(color1, color2);
    array[2].position = sf::Vector2f(origin.x + size.x, origin.y + size.y);
    array[2].color = color2;
    array[3].position = sf::Vector2f(origin.x + size.x, origin.y);
    array[3].color = getMixColor(color1, color2);
    return (array);
}

static sf::VertexArray getTriangle(sf::Vector2f pos1, sf::Vector2f pos2,
    sf::Vector2f pos3, sf::Color color)
{
    sf::VertexArray array(sf::Triangles, 3);
    array[0].position = pos1;
    array[0].color = color;
    array[1].position = pos2;
    array[1].color = color;
    array[2].position = pos3;
    array[2].color = color;
    return (array);
}

void MonitorSfml::displayButton(int x, int y, int offset, bool left,
    sf::Vector2i mouse)
{
    sf::VertexArray button;
    sf::VertexArray arrow;

    if (mouse.x >= 505 * x + 400 + offset &&
        mouse.x <= 505 * x + 450 + offset && mouse.y >= 505 * y &&
        mouse.y <= 505 * y + 50)
        button = getRectangle(sf::Vector2f(505 * x + 400 + offset, 505 * y),
            sf::Vector2f(50, 50), sf::Color(90, 90, 90), sf::Color(80, 80, 80));
    else
        button = getRectangle(sf::Vector2f(505 * x + 400 + offset, 505 * y),
            sf::Vector2f(50, 50), sf::Color(60, 60, 60), sf::Color(50, 50, 50));
    if (left)
        arrow = getTriangle(sf::Vector2f(505 * x + 410, 505 * y + 25),
            sf::Vector2f(505 * x + 435, 505 * y + 10),
            sf::Vector2f(505 * x + 435, 505 * y + 40),
            sf::Color(200, 200, 200));
    else
        arrow = getTriangle(sf::Vector2f(505 * x + 490, 505 * y + 25),
            sf::Vector2f(505 * x + 465, 505 * y + 10),
            sf::Vector2f(505 * x + 465, 505 * y + 40),
            sf::Color(200, 200, 200));
    _win->draw(button);
    _win->draw(arrow);
}

void MonitorSfml::displayModule(int x, int y, IMonitorModule *module)
{
    sf::Vector2i mouse = sf::Mouse::getPosition(*_win);
    sf::VertexArray background = getRectangle(sf::Vector2f(505 * x, 505 * y),
        sf::Vector2f(500, 500), sf::Color(30, 30, 30), sf::Color(40, 40, 40));
    _win->draw(background);
    if (module) {
        module->displaySfml(_win, sf::Vector2f(x, y));
    } else {
        SFML::Text text("NONE", "", 200 + (505 * x), 205 + (505 * y),
            sf::Color::White, sf::Color::White, sf::Color::Transparent, true);
        text.display(_win);
    }
    displayButton(x, y, 0, true, mouse);
    displayButton(x, y, 50, false, mouse);
}

void MonitorSfml::refreshWindow(IMonitorModule **modules, Settings settings)
{
    _win->clear(sf::Color::Black);
    sf::VertexArray background = getRectangle(sf::Vector2f(0, 0),
        sf::Vector2f(1005, 1005), sf::Color(10, 10, 10), sf::Color(30, 30, 30));
    _win->draw(background);
    for (int i = 0; i < 4; i++)
        displayModule(i % 2, i / 2, modules[i]);
    SFML::Text text("Q/ESCAPE: Quit the program     S: Swap display mode", "",
        3, 978);
    text.display(_win);
    _win->display();
    (void)settings;
}

sf::RenderWindow *MonitorSfml::getWindow()
{
    return (_win);
}