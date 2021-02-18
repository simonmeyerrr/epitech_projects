#ifndef CPP_RTYPE_2019_ROOM_HPP
#define CPP_RTYPE_2019_ROOM_HPP

#include "../AComponent.hpp"
#include "../../../../ProtocolTCP.hpp"
#include "../Button/Button.hpp"

class RoomDisplay {
public:
    using Callback = std::function<void (int nbRoom)>;

    ~RoomDisplay() = default;
    explicit RoomDisplay(sf::Vector2f pos, Callback cb, Callback cb2, Callback cb3);

    void render(sf::RenderWindow &);
    void update(bool exist, ProtocolTCP::Room room);
    void manageEvent(const sf::Event &event, sf::RenderWindow &win);

private:
    sf::Vector2f _pos;
    bool _exist;
    ProtocolTCP::Room _room;
    sf::RectangleShape _rect;
    sf::Font _font;
    sf::Text _roomName;
    sf::Text _roomState;
    std::unique_ptr<sf::Text> _playersName[PLAYERS_PER_ROOM];
    IComponentPtr _joinRoom;
    IComponentPtr _leaveRoom;
    IComponentPtr _startGame;
};

class Rooms : public AComponent {
public:
    using Callback = std::function<void (int nbRoom)>;
    ~Rooms() override = default;
    Rooms(int id, sf::Vector2f pos, int elemPerPage, ProtocolTCP::Rooms &rooms, int &page, Callback cb, Callback cb2, Callback cb3);

    void render(sf::RenderWindow &) override;
    void update() override;
    void manageEvent(const sf::Event &event, sf::RenderWindow &win) override;

private:
    sf::Vector2f _pos;
    int _elemPerPage;
    ProtocolTCP::Rooms &_rooms;
    int &_page;
    std::vector<std::unique_ptr<RoomDisplay>> _roomsDisplay;

};

#endif /* CPP_RTYPE_2019_ROOM_HPP */
