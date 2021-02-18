//
// Created by arnaud on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_VECTOR2S_HPP
#define CPP_RTYPE_2019_VECTOR2S_HPP


struct Vector2s {
    ~Vector2s() = default;
    Vector2s(short x = 0, short y = 0) : _x(x), _y(y) {}
    Vector2s(const Vector2s &copy) = default;
    Vector2s& operator=(const Vector2s &copy) {_x = copy._x; _y = copy._y; return *this;}

    short _x;
    short _y;
};


#endif //CPP_RTYPE_2019_VECTOR2S_HPP
