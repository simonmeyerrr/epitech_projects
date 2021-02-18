#ifndef CPP_RTYPE_2019_SCENECONNECTED_HPP
#define CPP_RTYPE_2019_SCENECONNECTED_HPP

#include <vector>
#include "../AScene.hpp"
#include "../../../ClientLauncher/IClientLauncher.hpp"

#define ROOM_PER_PAGE 4

class SceneConnected : public AScene {
public:
    ~SceneConnected() override = default;
    explicit SceneConnected(IClientLauncherPtr &client);

    void render(sf::RenderWindow &win) override;
    void update() override;
    void manageEvent(const sf::Event &event, sf::RenderWindow &win) override;

private:
    void pageNext();
    void pagePrev();
    IClientLauncherPtr &_client;
    ProtocolTCP::Rooms _rooms;
    int _page;
    std::string _roomName;
    int _selected;
    sf::Font _font;
    sf::Text _textPage;
    sf::Text _noRooms;
};


#endif //CPP_RTYPE_2019_SCENECONNECTED_HPP
