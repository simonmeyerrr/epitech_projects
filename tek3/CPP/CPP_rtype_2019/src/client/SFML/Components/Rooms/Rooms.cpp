#include "Rooms.hpp"
#include "../../../Config.hpp"

RoomDisplay::RoomDisplay(sf::Vector2f pos, Callback cb, Callback cb2, Callback cb3)
    : _pos(pos), _exist(false), _room(), _rect()
{
    _rect.setOutlineThickness(5.f);
    _rect.setOutlineColor(sf::Color(0, 0, 0));
    _rect.setFillColor(sf::Color(55, 55, 55));
    _rect.setPosition(pos);
    _rect.setSize({300, 220});

    _font.loadFromFile(ASSETS_PATH_STR "coolvetica.ttf");

    _roomName.setFont(_font);
    _roomName.setString("");
    _roomName.setCharacterSize(36);
    _roomName.setFillColor(sf::Color(180, 180, 180));
    _roomName.setPosition(sf::Vector2f(_pos.x + 24, _pos.y));

    _roomState.setFont(_font);
    _roomState.setString("");
    _roomState.setCharacterSize(36);
    _roomState.setFillColor(sf::Color(255, 255, 255));
    _roomState.setPosition(sf::Vector2f(_pos.x + 180, _pos.y + 170));

    for (int i = 0 ; i < PLAYERS_PER_ROOM ; ++i) {
        _playersName[i] = std::make_unique<sf::Text>();
        _playersName[i]->setFont(_font);
        _playersName[i]->setString("");
        _playersName[i]->setCharacterSize(36);
        _playersName[i]->setFillColor(sf::Color(55, 55, 55));
        _playersName[i]->setPosition(sf::Vector2f(_pos.x + 36, _pos.y + 40 + i * 36));
    }

    _joinRoom  = std::make_unique<Button>(
            0,
            sf::Vector2f(pos.x + 350, pos.y),
            "Join room",
            [this, cb](){
                cb(_room.nb);
            });
    _leaveRoom = std::make_unique<Button>(
            1,
            sf::Vector2f(pos.x + 350, pos.y),
            "Leave room",
            [this, cb2](){
                cb2(_room.nb);
            });
    _startGame = std::make_unique<Button>(
            2,
            sf::Vector2f(pos.x + 350, pos.y + 90),
            "Start game",
            [this, cb3](){
                cb3(_room.nb);
            });
}

void RoomDisplay::render(sf::RenderWindow &win)
{
    if (!_exist)
        return;
    win.draw(_rect);
    win.draw(_roomName);
    win.draw(_roomState);
    int youPos = 5;
    for (int i = 0 ; i < PLAYERS_PER_ROOM ; ++i) {
        if (_room.players[i].you)
            youPos = i;
        win.draw(*_playersName[i]);
    }
    int players_nb = 0;
    for (int i = 0 ; i < PLAYERS_PER_ROOM ; ++i)
        if (_room.players[i].exist)
            ++players_nb;
    if (youPos == 0)
        _startGame->render(win);
    if (youPos == 5) {
        if (players_nb != PLAYERS_PER_ROOM)
            _joinRoom->render(win);
    } else
        _leaveRoom->render(win);
}

void RoomDisplay::update(bool exist, ProtocolTCP::Room room)
{
    _exist = exist;
    _room = room;
    if (!_exist)
        return;
    std::string roomName = "#" + std::to_string(room.nb) + " : " + room.name;
    _roomName.setString(roomName.c_str());
    for (int i = 0 ; i < PLAYERS_PER_ROOM ; ++i) {
        _playersName[i]->setString(room.players[i].username);
        if (room.players[i].you)
            _playersName[i]->setFillColor(sf::Color(0, 255, 255));
        else
            _playersName[i]->setFillColor(sf::Color(255, 255, 255));
    }
    if (_room.launched)
        _roomState.setString("LAUNCHED");
    else {
        int players_nb = 0;
        for (int i = 0 ; i < PLAYERS_PER_ROOM ; ++i)
            if (_room.players[i].exist)
                ++players_nb;
        if (players_nb == PLAYERS_PER_ROOM)
            _roomState.setString("FULL");
        else
            _roomState.setString("");
    }
    _joinRoom->update();
    _leaveRoom->update();
    _startGame->update();
}

void RoomDisplay::manageEvent(const sf::Event &event, sf::RenderWindow &win)
{
    if (!_exist)
        return;
    int youPos = 5;
    for (int i = 0 ; i < PLAYERS_PER_ROOM ; ++i) {
        if (_room.players[i].you)
            youPos = i;
    }
    if (youPos == 5)
        _joinRoom->manageEvent(event, win);
    else
        _leaveRoom->manageEvent(event, win);
    if (youPos == 0)
        _startGame->manageEvent(event, win);
}

Rooms::Rooms(int id, sf::Vector2f pos, int elemPerPage, ProtocolTCP::Rooms &rooms, int &page, Callback cb, Callback cb2, Callback cb3)
    : AComponent(id), _pos(pos), _elemPerPage(elemPerPage), _rooms(rooms), _page(page), _roomsDisplay()
{
    int posx = pos.x;
    int posy = pos.y;
    for (int i = 0; i < elemPerPage; i++) {
        _roomsDisplay.push_back(std::make_unique<RoomDisplay>(
                sf::Vector2f(posx, posy), [cb](int nb){cb(nb);},
                [cb2](int nb){cb2(nb);}, [cb3](int nb){cb3(nb);}));
        if (i % 2 == 0)
            posx = 920;
        else {
            posx = 150;
            posy += 250;
        }
    }
}

void Rooms::render(sf::RenderWindow &win)
{
    for (auto &room: _roomsDisplay)
        room->render(win);
}

void Rooms::update()
{
    for (int i = 0; i < _elemPerPage; i++) {
        if (i + _elemPerPage * _page < static_cast<int>(_rooms.size()))
            _roomsDisplay[i]->update(true, _rooms[i + _elemPerPage * _page]);
        else
            _roomsDisplay[i]->update(false, {});
    }
}

void Rooms::manageEvent(const sf::Event &event, sf::RenderWindow &win)
{
    for (auto &room: _roomsDisplay)
        room->manageEvent(event, win);
}