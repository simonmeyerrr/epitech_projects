/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** text.cpp
*/

#include "Text.hpp"

void SFML::Text::setValue(std::string const &value)
{
    ValueText.setString(value);
}

SFML::Text::Text(std::string const &name, std::string const &value, unsigned x,
    unsigned y, sf::Color nameColor, sf::Color valueColor, sf::Color background,
    bool title)
{
    Font.loadFromFile("./assets/Prompt-Regular.ttf");
    if (!title) {
        NameText.setScale(sf::Vector2f(0.6, 0.6));
        ValueText.setScale(sf::Vector2f(0.6, 0.6));
    }

    NameText.setPosition(x, y);
    NameText.setString(name);
    NameText.setColor(nameColor);
    NameText.setFont(Font);

    ValueText.setPosition(x + 200, y);
    ValueText.setString(value);
    ValueText.setColor(valueColor);
    ValueText.setFont(Font);

    Background.setPosition(x, y);
    Background.setFillColor(background);
    Background.setSize(sf::Vector2f(
        NameText.getLocalBounds().width + ValueText.getLocalBounds().width + 20,
        NameText.getLocalBounds().height + ValueText.getLocalBounds().height));
}

void SFML::Text::display(sf::RenderWindow *window)
{
    window->draw(Background);
    window->draw(NameText);
    window->draw(ValueText);
}

void SFML::Text::setBackground(sf::Color color)
{
    Background.setFillColor(color);
}
