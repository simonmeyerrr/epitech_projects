#ifndef CPP_RTYPE_2019_ICLIENTGAME_HPP
#define CPP_RTYPE_2019_ICLIENTGAME_HPP

#include <memory>

class IClientGame {
public:
    virtual ~IClientGame() = default;


};

using IClientGamePtr = std::unique_ptr<IClientGame>;

#endif //CPP_RTYPE_2019_ICLIENTGAME_HPP
