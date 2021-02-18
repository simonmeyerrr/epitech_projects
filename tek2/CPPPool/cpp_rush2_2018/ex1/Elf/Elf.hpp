/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Elf.hpp
*/

#ifndef CPP_RUSH2_2018_ELF_HPP_
# define CPP_RUSH2_2018_ELF_HPP_

# include "IElf.hpp"

class Elf : public IElf {
public:
    Elf();
    ~Elf();

    void say(const std::string &) const;

    bool put(ITable &, int);
    bool take(ITable &, int);
    Object *const *look(const ITable &) const;

    bool put(IConveyorBelt &);
    bool take(IConveyorBelt &);
    const Object *look(const IConveyorBelt &) const;
    bool in(IConveyorBelt &, Object::Types) const;
    bool out(IConveyorBelt &) const;

    bool carrySomething() const;
    const Object *inMyHand() const;

private:
    Object *_obj;
};

#endif /* CPP_RUSH2_2018_ELF_HPP_ */
