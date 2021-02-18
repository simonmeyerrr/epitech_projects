/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Vector.cpp
*/

#include "Vector.hpp"

namespace arcade {
    Vector::Vector(int a, int b) : x(a), y(b)
    {}

    Vector::Vector(const Vector &v) : x(v.x), y(v.y)
    {}

    Vector &Vector::operator=(const Vector &v)
    {
        if (this == &v)
            return (*this);
        x = v.x;
        y = v.y;
        return (*this);
    }

    bool Vector::operator==(const Vector &v) const
    {
        return (x == v.x && y == v.y);
    }

    bool Vector::operator!=(const Vector &v) const
    {
        return (x != v.x || y != v.y);
    }

    bool Vector::operator<=(const Vector &v) const
    {
        return (x <= v.x && y <= v.y);
    }

    bool Vector::operator<(const Vector &v) const
    {
        return (x < v.x && y < v.y);
    }

    bool Vector::operator>=(const Vector &v) const
    {
        return (x >= v.x && y >= v.y);
    }

    bool Vector::operator>(const Vector &v) const
    {
        return (x > v.x && y > v.y);
    }
}