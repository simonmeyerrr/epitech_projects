#ifndef CPP_RTYPE_2019_SCENEGAME_HPP
#define CPP_RTYPE_2019_SCENEGAME_HPP

#include "../AScene.hpp"
#include "../../../ClientLauncher/IClientLauncher.hpp"
#include "../../../ClientGame/MyClientGame.hpp"
#include "TextureLoader/TextureLoader.hpp"

class SceneGame : public AScene {
public:
    ~SceneGame() override = default;
    explicit SceneGame(IClientLauncherPtr &client);

    void render(sf::RenderWindow &win) override;
    void update() override;
    void manageEvent(const sf::Event &event, sf::RenderWindow &win) override;

private:
    IClientLauncherPtr &_clientLauncher;
    std::unique_ptr<MyClientGame> _clientGame;

    ProtocolUDP::ActionMovePlayer _movement;
    ProtocolUDP::InfoPlayers _infoPlayers;
    ProtocolUDP::Entities  _entities;
    TextureLoader _loader;
};


#endif /* CPP_RTYPE_2019_SCENEGAME_HPP */
