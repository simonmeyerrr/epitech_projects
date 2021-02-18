/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Sfml.hpp
*/
#ifndef OOP_ARCADE_2018_SFML_HPP
# define OOP_ARCADE_2018_SFML_HPP

# include <SFML/Graphics.hpp>
# include "IGraphic.hpp"

namespace arcade {
    class Sfml : public IGraphic {
    public:
        ~Sfml();
        Sfml();

        Event getEvent();
        void clearWindow(Color color = ARCADE_BLACK);
        void displayWindow();
        void printPixel(Vector v, Color color = ARCADE_WHITE);
        void printRectangle(Vector pos, Vector size, Color color = ARCADE_WHITE);
        void printText(Vector v, const std::string &text, Color color = ARCADE_WHITE,
            Color background = ARCADE_TRANSPARENT);

    private:
        Event manageKeyPressed(sf::Keyboard::Key key);
        Event manageMousePressed(sf::Event::MouseButtonEvent mouse);
        sf::Color getColor(Color color);

        sf::RenderWindow _win;
        sf::Font _font;
    };
}

#endif /* OOP_ARCADE_2018_SFML_HPP */
