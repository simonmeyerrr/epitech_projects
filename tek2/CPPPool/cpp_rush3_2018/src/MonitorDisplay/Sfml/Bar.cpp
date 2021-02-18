/*
** EPITECH PROJECT, 2018
** Project
** File description:
** Source file
*/

#include "Bar.hpp"

SFML::Bar::Bar(const std::string & name, float max, unsigned x, unsigned y,
               const std::string & unit)
    : Max(max), Unit(unit), X(x), Y(y)
{
    this->Value = 0;
    this->Font.loadFromFile("./assets/Prompt-Regular.ttf");

    this->NameText.setPosition(x, y);
    this->NameText.setScale(sf::Vector2f(0.5, 0.5));
    this->NameText.setString(name);
    this->NameText.setFont(Font);

    this->PercentText.setPosition(x + 240, y);
    this->PercentText.setScale(sf::Vector2f(0.5, 0.5));
    this->PercentText.setString("0%");
    this->PercentText.setFont(Font);

    this->ProgressText.setPosition(x + 410, y - 15);
    this->ProgressText.setString("0 /\n" + std::to_string((int)max) + " " + Unit);
    this->ProgressText.setScale(sf::Vector2f(0.5, 0.5));
    this->ProgressText.setFont(Font);

    this->ProgressBarBg = getRectangle(sf::Vector2f(x + 100, y), sf::Vector2f(300, 20), sf::Color::Green, sf::Color::Red);
    this->ProgressBar.setFillColor(sf::Color::Black);
    this->ProgressBar.setPosition(x + 100, y);
    this->ProgressBar.setSize(sf::Vector2f(300, 20));
    this->ProgressBarOutline.setFillColor(sf::Color::Black);
    this->ProgressBarOutline.setPosition(x + 98, y - 2);
    this->ProgressBarOutline.setSize(sf::Vector2f(304, 24));

}

void SFML::Bar::setValue(float value)
{
    this->Value = value;

    this->PercentText.setString(std::to_string((int)(Value / Max * 100)) + "%");
    this->ProgressText.setString(std::to_string((int)Value) + " /\n" +
                                     std::to_string((int)Max) + " " + Unit);
    this->ProgressBar.setPosition(X + 100 + (Value / Max * 300), Y);
    this->ProgressBar.setSize(sf::Vector2f(300 - (Value / Max * 300), 20));
}

sf::Color SFML::Bar::getMixColor(sf::Color color1, sf::Color color2)
{
    sf::Uint8 r = (color1.r + color2.r) / (sf::Uint8)2;
    sf::Uint8 g = (color1.g + color2.g) / (sf::Uint8)2;
    sf::Uint8 b = (color1.b + color2.b) / (sf::Uint8)2;
    sf::Uint8 a = (color1.a + color2.a) / (sf::Uint8)2;
    sf::Color color(r, g, b, a);
    return (color);
}

sf::VertexArray SFML::Bar::getRectangle(sf::Vector2f origin, sf::Vector2f size,
                             sf::Color color1, sf::Color color2)
{
    sf::VertexArray array(sf::Quads, 4);
    array[0].position = origin;
    array[0].color = color1;
    array[1].position = sf::Vector2f(origin.x, origin.y + size.y);
    array[1].color = color1;
    array[2].position = sf::Vector2f(origin.x + size.x, origin.y + size.y);
    array[2].color = color2;
    array[3].position = sf::Vector2f(origin.x + size.x, origin.y);
    array[3].color = color2;
    return (array);
}

void SFML::Bar::display(sf::RenderWindow *window)
{
    window->draw(ProgressBarOutline);
    window->draw(ProgressBarBg);
    window->draw(ProgressBar);
    window->draw(PercentText);
    window->draw(ProgressText);
    window->draw(NameText);
}
