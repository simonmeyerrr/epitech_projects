/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** text.hpp
*/

#include <string>
#include <SFML/Graphics.hpp>

namespace SFML {
    class Text {
    public:
        ~Text() = default;
        Text(std::string const &name, std::string const &value, unsigned x,
            unsigned y, sf::Color nameColor = sf::Color::White,
            sf::Color valueColor = sf::Color::White,
            sf::Color background = sf::Color::Transparent, bool title = false);

        void setValue(std::string const &value);
        void setBackground(sf::Color = sf::Color::Transparent);
        void display(sf::RenderWindow *window);

    private:
        sf::Text NameText;
        sf::Text ValueText;
        sf::Font Font;
        sf::RectangleShape Background;
    };
}
