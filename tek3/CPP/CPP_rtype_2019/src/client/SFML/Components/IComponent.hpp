#ifndef CPP_RTYPE_2019_ICOMPONENT_HPP
#define CPP_RTYPE_2019_ICOMPONENT_HPP

#include <SFML/Graphics.hpp>

class IComponent {
public:
    virtual ~IComponent() = default;

    virtual int getId() const = 0;
    virtual void render(sf::RenderWindow &) = 0;
    virtual void update() = 0;
    virtual void manageEvent(const sf::Event &, sf::RenderWindow &) = 0;
};

using IComponentPtr = std::unique_ptr<IComponent>;

#endif //CPP_RTYPE_2019_ICOMPONENT_HPP
