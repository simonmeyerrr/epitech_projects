/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Object.hpp
*/

#ifndef CPP_RUSH2_2018_OBJECT_HPP_
# define CPP_RUSH2_2018_OBJECT_HPP_

# include <iostream>
# include <string>

class Object {
public:
    const std::string mainTypeName[2] = {"toy", "wrap"};
    enum MainTypes {
        TOY,
        WRAP,
    };

    const std::string typeName[4] = {"teddy", "little pony", "paper", "box"};
    enum Types {
        TEDDY,
        LITTLEPONY,
        PAPER,
        BOX
    };

    Object(MainTypes, Types, const std::string &);
    virtual ~Object();

    // all
    virtual int getObjectCount() const = 0;
    virtual void say(const std::string &) const;
    virtual std::string describe() const = 0;
    MainTypes getMainType() const;
    Types getType() const;
    std::string getTitle() const;

    // Toy
    virtual void isTaken() const = 0;

    // Wrap
    virtual void openMe() = 0;
    virtual void closeMe() = 0;
    virtual bool isOpen() const = 0;
    virtual bool wrapMeThat(Object *) = 0;
    virtual Object *takeObject() = 0;
    virtual const Object *getObject() const = 0;

private:
    MainTypes _mainType;
    Types _type;
    std::string _title;
};

std::ostream &operator<<(std::ostream &stream, const Object &obj);
Object **MyUnitTests();

#endif /* CPP_RUSH2_2018_OBJECT_HPP_ */
