/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Vector.hpp
*/

#ifndef OOP_ARCADE_2018_VECTOR_HPP
# define OOP_ARCADE_2018_VECTOR_HPP

namespace arcade {
    class Vector {
    public:
        ~Vector() = default;

        Vector(int a = 0, int b = 0);
        Vector(const Vector &v);

        Vector &operator=(const Vector &v);
        bool operator==(const Vector &v) const;
        bool operator!=(const Vector &v) const;
        bool operator<=(const Vector &v) const;
        bool operator<(const Vector &v) const;
        bool operator>=(const Vector &v) const;
        bool operator>(const Vector &v) const;

        int x;
        int y;
    };
}

#endif /* OOP_ARCADE_2018_VECTOR_HPP */
