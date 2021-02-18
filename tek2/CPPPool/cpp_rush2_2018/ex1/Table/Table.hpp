/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Table.hpp
*/

#ifndef CPP_RUSH2_2018_TABLE_HPP_
# define CPP_RUSH2_2018_TABLE_HPP_

# include "ITable.hpp"

class Table : public ITable {
public:
    Table();
    ~Table();

    void say(const std::string &str) const;
    bool isBroken() const;
    void deleteTabContent();
    int getObjCount() const;
    Object *const *getObjTab() const;

    Object *takeObjAtPos(int index);
    bool setObjAtPos(Object *obj, int index);

private:
    bool setObj(Object *obj, int index);

    Object *_objTab[10];
    bool _isBroken;
};

#endif /* CPP_RUSH2_2018_TABLE_HPP_ */
