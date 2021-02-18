/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex05.hpp
*/

#ifndef CPP_D15_2018_EX05_HPP_
# define CPP_D15_2018_EX05_HPP_

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class array {
public:
    ~array()
    {
        if (_array)
            delete [] _array;
    }

    array() : _size(0), _array(nullptr)
    {
    }

    array(unsigned int size) : _size(size), _array(nullptr)
    {
        if (_size)
            _array = new T[_size] ();
    }

    array(const array &other) : _size(other._size), _array(nullptr)
    {
        if (_size) {
            _array = new T[_size] ();
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
    }

    array &operator=(const array &other)
    {
        if (this == &other)
            return (*this);
        if (_array)
            delete [] _array;
        _array = nullptr;
        _size = other._size;
        if (_size) {
            _array = new T[_size] ();
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        return (*this);
    }

    T &operator[](unsigned int pos)
    {
        if (pos >= _size) {
            T *tab = new T[pos + 1] ();
            for (unsigned int i = 0; i < _size; i++)
                tab[i] = _array[i];
            if (_array)
                delete [] _array;
            _array = tab;
            _size = pos + 1;
        }
        return (_array[pos]);
    }

    T &operator[](unsigned int pos) const
    {
        if (pos >= _size)
            throw std::exception();
        return (_array[pos]);
    }

    unsigned int size() const
    {
        return _size;
    }

    void dump() const
    {
        std::cout << "[";
        for (unsigned int i = 0; _size > 0 && i < _size - 1; i++)
            std::cout << _array[i] << ", ";
        if (_size)
            std::cout << _array[_size - 1];
        std::cout << "]" << std::endl;
    }

    template<typename U>
    array<U> convertTo(U (*func)(const T &toChange)) const
    {
        array<U> a(_size);
        for (unsigned int i = 0; i < _size; i++)
            a[i] = func(_array[i]);
        return (a);
    }

private:
    unsigned int _size;
    T *_array;
};

template<>
void array<bool>::dump() const
{
    std::cout << "[";
    for (unsigned int i = 0; _size > 0 && i < _size - 1; i++)
        std::cout << (_array[i] ? "true" : "false") << ", ";
    if (_size)
        std::cout << (_array[_size - 1] ? "true" : "false");
    std::cout << "]" << std::endl;
}

#endif /* CPP_D15_2018_EX05_HPP_ */
