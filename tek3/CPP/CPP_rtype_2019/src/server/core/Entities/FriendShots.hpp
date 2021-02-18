//
// Created by arnaud on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_FRIENDSHOTS_HPP
#define CPP_RTYPE_2019_FRIENDSHOTS_HPP


#include "AEntity.hpp"

class FriendShots : public AEntity {
public:
    ~FriendShots() override = default;
    explicit FriendShots(Vector2s pos);

    void update() override;
};


#endif //CPP_RTYPE_2019_FRIENDSHOTS_HPP
