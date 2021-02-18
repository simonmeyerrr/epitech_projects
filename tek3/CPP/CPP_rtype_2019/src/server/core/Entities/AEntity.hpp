//
// Created by arnaud on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_AENTITY_HPP
#define CPP_RTYPE_2019_AENTITY_HPP

#include "IEntity.hpp"
#include "../../../Utils/Vector2s.hpp"

class AEntity : public IEntity {
public:
    ~AEntity() override = default;
    AEntity(const Vector2s &pos, const Vector2s &size, ProtocolUDP::EntityType type)
    : _pos(pos), _size(size), _type(type) {}

    Vector2s getPos() const override {return _pos;}
    Vector2s getSize() const override {return _size;}
    ProtocolUDP::EntityType getType() const override {return _type;}

protected:
    Vector2s _pos;
    Vector2s _size;
    ProtocolUDP::EntityType _type;
};

#endif //CPP_RTYPE_2019_AENTITY_HPP
