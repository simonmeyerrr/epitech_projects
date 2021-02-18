/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** ITable.hpp
*/

#ifndef CPP_RUSH2_2018_ITABLE_HPP_
# define CPP_RUSH2_2018_ITABLE_HPP_

# include "../Object/Object.hpp"

class ITable {
public:
    virtual ~ITable() {}

    virtual void say(const std::string &str) const = 0;
    virtual bool isBroken() const = 0;
    virtual void deleteTabContent() = 0;
    virtual int getObjCount() const = 0;
    virtual Object *const *getObjTab() const = 0;

    virtual Object *takeObjAtPos(int index) = 0;
    virtual bool setObjAtPos(Object *obj, int index) = 0;

protected:
    virtual bool setObj(Object *obj, int index) = 0;
};

ITable *createTable();
ITable *createTableRand();

#endif /* CPP_RUSH2_2018_ITABLE_HPP_ */
