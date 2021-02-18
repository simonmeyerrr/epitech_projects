//
// Created by arnaud on 27/11/2019.
//

#ifndef CPP_RTYPE_2019_FASTMONSTER_HPP
#define CPP_RTYPE_2019_FASTMONSTER_HPP

#include "../server/core/Entities/AEntity.hpp"

class FastMonster : public AEntity {
public:
    ~FastMonster() override = default;
    FastMonster(int ypos);

    void update() override;
};


#endif //CPP_RTYPE_2019_FASTMONSTER_HPP
