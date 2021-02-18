#ifndef CPP_RTYPE_2019_ACLIENTGAME_HPP
#define CPP_RTYPE_2019_ACLIENTGAME_HPP

#include <memory>
#include "IClientGame.hpp"

class AClientGame : public IClientGame {
public:
    virtual ~AClientGame() override = default;
    explicit AClientGame() {}
};

#endif //CPP_RTYPE_2019_ACLIENTGAME_HPP
