//
// Created by arnaud on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_IENTITY_HPP
#define CPP_RTYPE_2019_IENTITY_HPP

#include "../../../Utils/Vector2s.hpp"
#include "../../../ProtocolUDP.hpp"

class IEntity {
public:
    virtual ~IEntity() = default;

    virtual void update() = 0;

    virtual Vector2s getPos() const = 0;
    virtual Vector2s getSize() const = 0;
    virtual ProtocolUDP::EntityType getType() const = 0;
};


#endif //CPP_RTYPE_2019_IENTITY_HPP
