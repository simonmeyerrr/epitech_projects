#include <iostream>
#include "SceneConnected.hpp"
#include "../../Components/Rooms/Rooms.hpp"
#include "../../Components/Button/Button.hpp"
#include "../../Components/InputField/InputField.hpp"

SceneConnected::SceneConnected(IClientLauncherPtr &client)
    : AScene(IScene::SCENE_CONNECTED), _client(client), _rooms(), _page(0), _roomName(), _selected(1)
{
    _font.loadFromFile(ASSETS_PATH_STR "coolvetica.ttf");

    _textPage.setFont(_font);
    _textPage.setCharacterSize(36);
    _textPage.setFillColor(sf::Color(255, 255, 255));
    _textPage.setPosition(sf::Vector2f(780, 680));

    _noRooms.setFont(_font);
    _noRooms.setCharacterSize(72);
    _noRooms.setFillColor(sf::Color(255, 255, 255));
    _noRooms.setPosition(sf::Vector2f(700, 360));
    _noRooms.setString("NO ROOMS");

    _components.emplace_back(IComponentPtr(new Rooms(
            0,
            {150, 20},
            ROOM_PER_PAGE,
            _rooms,
            _page,
            [this](int nb) {
                std::cout << "Join room " << nb << std::endl;
                _client->joinRoom(nb);
            },
            [this](int nb) {
                std::cout << "Leave room " << nb << std::endl;
                _client->leaveRoom();
            },
            [this](int nb) {
                std::cout << "Start game " << nb << std::endl;
                _client->startGame();
            }
    )));
    _components.emplace_back(IComponentPtr(new InputField(
            1,
            {700, 750},
            [this](const std::string &str){_roomName = str;},
            _selected,
            "Room name")
    ));
    _components.emplace_back(IComponentPtr(new Button(
            1,
            {701, 825},
            "Create room",
            [this](){_client->createRoom(_roomName);}
            )));
    _components.emplace_back(IComponentPtr(new Button(
            1,
            {1518, 425},
            ">>  ",
            [this](){pageNext();}
    )));
    _components.emplace_back(IComponentPtr(new Button(
            1,
            {10, 425},
            "<<  ",
            [this](){pagePrev();}
    )));
}

void SceneConnected::pageNext()
{
    _page++;
}

void SceneConnected::pagePrev()
{
    if (_page > 0)
        _page--;
}

void SceneConnected::render(sf::RenderWindow &win)
{
    AScene::render(win);
    win.draw(_textPage);
    if (_rooms.empty())
        win.draw(_noRooms);
}

void SceneConnected::update()
{
    int roomMax = (int)_rooms.size() / ROOM_PER_PAGE;

    if (_rooms.size() < ROOM_PER_PAGE)
        roomMax = 1;
    else if (_rooms.size() % ROOM_PER_PAGE != 0)
        roomMax += 1;
    std::string str = std::to_string(_page + 1) + " / " + std::to_string(roomMax);
    _textPage.setString(str.c_str());
    _rooms = _client->getRooms();
    AScene::update();
}

void SceneConnected::manageEvent(const sf::Event &event, sf::RenderWindow &win)
{
    AScene::manageEvent(event, win);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
        _client->createRoom(_roomName);
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        _client->disconnect();
}
