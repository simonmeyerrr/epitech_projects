#ifndef CPP_RTYPE_2019_ASCENE_HPP
#define CPP_RTYPE_2019_ASCENE_HPP

#include "IScene.hpp"
#include "../Components/IComponent.hpp"

class AScene : public IScene {
public:
    virtual ~AScene() override = default;
    explicit AScene(SceneType type) : _type(type), _components() {}

    void render(sf::RenderWindow &win) override {
        for (auto &component : _components)
            component->render(win);
    }

    void update() override {
        for (auto &component : _components)
            component->update();
    }

    void manageEvent(const sf::Event &event, sf::RenderWindow &win) override {
        for (auto &component : _components)
            component->manageEvent(event, win);
    }

    SceneType getType() const override {return _type;}

protected:
    SceneType _type;
    std::vector<IComponentPtr> _components;

};

#endif //CPP_RTYPE_2019_ASCENE_HPP
