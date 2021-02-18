#include <iostream>
#include "SceneGame.hpp"

SceneGame::SceneGame(IClientLauncherPtr &client)
    : AScene(IScene::SCENE_GAME), _clientLauncher(client), _clientGame(nullptr),
    _movement{false, false, false, false}, _infoPlayers(), _entities(), _loader()
{
    for (int i = 0; i < PLAYERS_PER_ROOM; i++)
        _infoPlayers[i] = {false, false, 0, 0};
    _clientGame = std::make_unique<MyClientGame>(client->getIp(), client->getPort(), client->getMyId());
}

void SceneGame::render(sf::RenderWindow &win)
{
    ProtocolUDP::EntityType types[4] = {ProtocolUDP::PLAYER1, ProtocolUDP::PLAYER2, ProtocolUDP::PLAYER3, ProtocolUDP::PLAYER4};
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        if (_infoPlayers[i].alive && _infoPlayers[i].connected)
            _loader.render({static_cast<float>(_infoPlayers[i].pos_x), static_cast<float>(_infoPlayers[i].pos_y)}, win, types[i]);
    }
    for (const auto &entity: _entities)
        _loader.render({static_cast<float>(entity.pos_x), static_cast<float>(entity.pos_y)}, win, static_cast<ProtocolUDP::EntityType>(entity.type));
}

void SceneGame::update()
{
	_clientGame->readPackets();
    _clientGame->sendMove(_movement);
    _clientGame->readPackets();
    std::memcpy(_infoPlayers, _clientGame->getInfoPlayers(), sizeof(ProtocolUDP::InfoPlayers));
    _entities = _clientGame->getEntities();
    _loader.update();
}

void SceneGame::manageEvent(const sf::Event &event, sf::RenderWindow &win)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        _clientLauncher->leaveRoom();
    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::Z:
                _movement.up = event.type == sf::Event::KeyPressed;
                break;
            case sf::Keyboard::D:
                _movement.right = event.type == sf::Event::KeyPressed;
                break;
            case sf::Keyboard::S:
                _movement.down = event.type == sf::Event::KeyPressed;
                break;
            case sf::Keyboard::Q:
                _movement.left = event.type == sf::Event::KeyPressed;
                break;
            default:
                break;
        }
    }
}