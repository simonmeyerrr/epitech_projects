#ifndef CPP_RTYPE_2019_SCENECONNECTING_HPP
#define CPP_RTYPE_2019_SCENECONNECTING_HPP

#include <vector>
#include "../AScene.hpp"
#include "../../../ClientLauncher/IClientLauncher.hpp"
#include "../../../Config.hpp"

#define FILENAMEINFOS "infosUser"

class SceneConnecting : public AScene {
public:
    enum {
        USERNAME = 0,
        IP = 1,
        PORT = 2,
        LOGIN = 3
    };

    ~SceneConnecting() override = default;
    explicit SceneConnecting(IClientLauncherPtr &client);

    void render(sf::RenderWindow &win) override;
    void update() override;
    void manageEvent(const sf::Event &event, sf::RenderWindow &win) override;

private:
    void login();
    void saveInfos();
    void loadInfos();

    IClientLauncherPtr &_client;
    std::string _username;
    std::string _ip;
    std::string _port;
    int _selected;
    sf::Texture _texture;
    sf::Sprite _sprite;

};

#endif //CPP_RTYPE_2019_SCENECONNECTING_HPP
