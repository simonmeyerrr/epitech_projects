//
// Created by arnaud on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_SLOWMONSTER_HPP
#define CPP_RTYPE_2019_SLOWMONSTER_HPP


#include "../server/core/Entities/AEntity.hpp"

class SlowMonster : public AEntity {
public:
    ~SlowMonster() override = default;
    SlowMonster(int ypos);

    void update() override;
};


#endif //CPP_RTYPE_2019_SLOWMONSTER_HPP
