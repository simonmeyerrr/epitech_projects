/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** bar.hpp
*/

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace SFML {
    class Bar {
    public:
        ~Bar() = default;
        Bar(std::string const &name, float max, unsigned x, unsigned y,
            std::string const &unit);

        void setValue(float value);
        void display(sf::RenderWindow *);

    private:
        sf::Color getMixColor(sf::Color, sf::Color);
        sf::VertexArray getRectangle(sf::Vector2f, sf::Vector2f, sf::Color,
            sf::Color);

        float const Max;
        std::string const Unit;
        float Value = 0;
        sf::Text NameText;
        sf::Text PercentText;
        sf::Text ProgressText;
        sf::Font Font;
        sf::VertexArray ProgressBarBg;
        sf::RectangleShape ProgressBar;
        sf::RectangleShape ProgressBarOutline;
        int X;
        int Y;
    };
}
