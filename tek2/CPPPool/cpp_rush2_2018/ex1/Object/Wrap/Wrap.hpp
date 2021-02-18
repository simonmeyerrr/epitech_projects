/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Wrap.hpp
*/

#ifndef CPP_RUSH2_2018_WRAP_HPP_
# define CPP_RUSH2_2018_WRAP_HPP_

# include "../Object.hpp"

class Wrap : public Object {
public:
    Wrap(Object::Types, const std::string &);
    Wrap(Object::Types, Object *);
    virtual ~Wrap();

    void openMe();
    void closeMe();
    bool isOpen() const;

    int getObjectCount() const;

    void isTaken() const;

protected:
    bool _open;
    Object *_obj;
};

#endif /* CPP_RUSH2_2018_WRAP_HPP_ */
