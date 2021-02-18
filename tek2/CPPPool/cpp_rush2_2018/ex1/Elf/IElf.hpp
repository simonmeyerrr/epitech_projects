/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** IElf.hpp
*/

#ifndef CPP_RUSH2_2018_IELF_HPP_
# define CPP_RUSH2_2018_IELF_HPP_

# include "../ConveyorBelt/IConveyorBelt.hpp"
# include "../Table/ITable.hpp"
# include "../Object/Object.hpp"

class IElf {
public:
    virtual ~IElf() {}

    virtual void say(const std::string &) const = 0;

    virtual bool put(ITable &, int) = 0;
    virtual bool take(ITable &, int) = 0;
    virtual Object *const *look(const ITable &) const = 0;

    virtual bool put(IConveyorBelt &) = 0;
    virtual bool take(IConveyorBelt &) = 0;
    virtual const Object *look(const IConveyorBelt &) const = 0;
    virtual bool in(IConveyorBelt &, Object::Types) const = 0;
    virtual bool out(IConveyorBelt &) const = 0;

    virtual bool carrySomething() const = 0;
    virtual const Object *inMyHand() const = 0;
};

#endif /* CPP_RUSH2_2018_IELF_HPP_ */
