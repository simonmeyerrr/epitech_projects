/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGraphic.hpp
*/

#ifndef OOP_ARCADE_2018_IGRAPHIC_HPP
# define OOP_ARCADE_2018_IGRAPHIC_HPP

# include <string>
# include "Vector.hpp"
# include "Event.hpp"
# include "Color.hpp"

namespace arcade {
    class IGraphic {
    public:
        virtual ~IGraphic() = default;

        virtual Event getEvent() = 0;
        virtual void clearWindow(Color color = ARCADE_BLACK) = 0;
        virtual void displayWindow() = 0;
        virtual void printPixel(Vector v, Color color = ARCADE_WHITE) = 0;
        virtual void printRectangle(Vector pos, Vector size,
            Color color = ARCADE_WHITE) = 0;
        virtual void printText(Vector v, const std::string &text,
            Color color = ARCADE_WHITE, Color background = ARCADE_TRANSPARENT) = 0;
    };
}

#endif /* OOP_ARCADE_2018_IGRAPHIC_HPP */
