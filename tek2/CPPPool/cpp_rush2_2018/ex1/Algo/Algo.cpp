/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Algo.cpp
*/

#include "Algo.hpp"

Algo::Algo(IConveyorBelt *conv, ITable *table, IElf *elf)
    : _conv(conv), _table(table), _elf(elf)
{
    if (!conv || !table || !elf) {
        say("Parameters shouldn't be null");
        return;
    }
    say("START");
    getContents();
    while (doSomething())
        getContents();
    _elf->say("o'pa ere's somin' wron' in da box!");
}

Algo::~Algo()
{
    say("END");
    if (_conv)
        delete _conv;
    if (_table)
        delete _table;
    if (_elf)
        delete _elf;
}

void Algo::say(const std::string &message) const
{
    std::cout << "[ALGO] " << message << std::endl;
}

void Algo::getContents()
{
    _convContent = _elf->look(*_conv);
    _tableContent = _elf->look(*_table);
    _elfContent = _elf->inMyHand();
}

bool Algo::doSomething()
{
    if (!isThereAToy())
        return (false);
    if (action1())
        return (true);
    if (action2())
        return (true);
    if (action3())
        return (true);
    if (action4())
        return (true);
    if (action5())
        return (true);
    if (action6())
        return (true);
    if (action7())
        return (true);
    if (action8())
        return (true);
    if (action9())
        return (true);
    if (action10())
        return (true);
    return (false);
}

bool Algo::isThereAToy()
{
    for (int i = 0; i < 10; i++) {
        if (containsAToy(_tableContent[i]))
            return (true);
    }
    if (containsAToy(_convContent))
        return (true);
    if (containsAToy(_elfContent))
        return (true);
    return (false);
}

bool Algo::containsAToy(const Object *obj)
{
    if (obj && obj->getMainType() == Object::TOY)
        return (true);
    if (obj && obj->getObject())
        return (containsAToy(obj->getObject()));
    return (false);
}

// carry toy
bool Algo::action1()
{
    if (!_elfContent || _elfContent->getMainType() != Object::TOY)
        return (false);

    if (_convContent && _convContent->getType() == Object::BOX &&
        _convContent->isOpen()) {
        _elf->put(*_conv);
        _elf->take(*_conv);
        return (true);
    }

    if (_table->isBroken())
        return (false);

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] && _tableContent[i]->getType() == Object::BOX &&
        _tableContent[i]->isOpen()) {
            _elf->put(*_table, i);
            _elf->take(*_table, i);
            return (true);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (true);
        }
    }

    return (false);
}

// carry box with toy
bool Algo::action2()
{
    if (!_elfContent || _elfContent->getType() != Object::BOX
        || _elfContent->isOpen())
        return (false);

    if (_convContent && _convContent->getType() == Object::PAPER &&
        _convContent->isOpen()) {
        _elf->put(*_conv);
        _elf->out(*_conv);
        return (true);
    }

    if (_table->isBroken())
        return (false);

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] && _tableContent[i]->getType() == Object::PAPER &&
            _tableContent[i]->isOpen()) {
            _elf->put(*_table, i);
            _elf->take(*_table, i);
            return (true);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (true);
        }
    }

    return (false);
}

// carry empty box
bool Algo::action3()
{
    if (!_elfContent || _elfContent->getType() != Object::BOX
        || !_elfContent->isOpen())
        return (false);

    if (!_convContent) {
        _elf->put(*_conv);
        return (true);
    }

    if (_table->isBroken())
        return (false);

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (true);
        }
    }

    return (false);
}

// carry paper full
bool Algo::action4()
{
    if (!_elfContent || _elfContent->getType() != Object::PAPER
        || _elfContent->isOpen())
        return (false);

    if (!_convContent) {
        _elf->put(*_conv);
        _elf->out(*_conv);
        return (true);
    }

    if (_table->isBroken())
        return (false);

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (true);
        }
    }

    return (false);
}

// carry paper empty
bool Algo::action5()
{
    if (!_elfContent || _elfContent->getType() != Object::PAPER
        || !_elfContent->isOpen())
        return (false);

    if (!_convContent) {
        _elf->put(*_conv);
        return (true);
    }

    if (_table->isBroken())
        return (false);

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (true);
        }
    }

    return (false);
}

// carry nothing search toy to put
bool Algo::action6()
{
    if (_elfContent)
        return (false);

    if (_table->isBroken())
        return (false);

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] && _tableContent[i]->getMainType() ==
        Object::TOY) {
            _elf->take(*_table, i);
            break;
        }
    }

    if (!_elf->carrySomething())
        return (false);

    if (_convContent && _convContent->getType() == Object::BOX &&
        _convContent->isOpen()) {
        _elf->put(*_conv);
        _elf->take(*_conv);
        return (true);
    }

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] && _tableContent[i]->getType() == Object::BOX &&
            _tableContent[i]->isOpen()) {
            _elf->put(*_table, i);
            _elf->take(*_table, i);
            return (true);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (false);
        }
    }

    return (false);
}

// carry nothing search box to wrap
bool Algo::action7()
{
    if (_elfContent)
        return (false);

    if (_table->isBroken())
        return (false);

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] && _tableContent[i]->getType() == Object::BOX &&
        !_tableContent[i]->isOpen()) {
            _elf->take(*_table, i);
            break;
        }
    }
    if (!_elf->carrySomething())
        return (false);

    if (_convContent && _convContent->getType() == Object::PAPER &&
        _convContent->isOpen()) {
        _elf->put(*_conv);
        _elf->out(*_conv);
        return (true);
    }

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] && _tableContent[i]->getType() == Object::PAPER &&
            _tableContent[i]->isOpen()) {
            _elf->put(*_table, i);
            _elf->take(*_table, i);
            return (true);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (false);
        }
    }

    return (false);
}

// carry nothing conv something
bool Algo::action8()
{
    if (_elfContent || !_convContent || _table->isBroken())
        return (false);

    _elf->take(*_conv);

    for (int i = 0; i < 10; i++) {
        if (!_tableContent[i]) {
            _elf->put(*_table, i);
            return (true);
        }
    }

    _elf->put(*_conv);

    return (false);
}

// carry nothing need paper
bool Algo::action9()
{
    if (_elfContent || _convContent)
        return (false);

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] && _tableContent[i]->getType() == Object::BOX &&
            !_tableContent[i]->isOpen()) {
            _elf->in(*_conv, Object::PAPER);
            return (true);
        }
    }

    return (false);
}

// carry nothing need box
bool Algo::action10()
{
    if (_elfContent || _convContent)
        return (false);

    for (int i = 0; i < 10; i++) {
        if (_tableContent[i] &&
            _tableContent[i]->getMainType() == Object::TOY) {
            _elf->in(*_conv, Object::BOX);
            return (true);
        }
    }

    return (false);
}