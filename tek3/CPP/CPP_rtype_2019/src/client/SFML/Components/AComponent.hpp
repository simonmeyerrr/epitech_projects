#ifndef CPP_RTYPE_2019_ACOMPONENT_HPP
#define CPP_RTYPE_2019_ACOMPONENT_HPP

#include "IComponent.hpp"

class AComponent : public IComponent {
public:
    virtual ~AComponent() override = default;
    explicit AComponent(int id) : _id(id) {}

    int getId() const override {return _id;}

protected:
    int _id;
};

#endif //CPP_RTYPE_2019_ACOMPONENT_HPP
