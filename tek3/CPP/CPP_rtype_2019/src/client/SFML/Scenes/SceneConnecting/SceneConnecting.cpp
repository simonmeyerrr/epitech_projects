#include <iostream>
#include <fstream>
#include "SceneConnecting.hpp"
#include "../../Components/Button/Button.hpp"
#include "../../Components/InputField/InputField.hpp"
#include "../../../../socket/Utils.hpp"

SceneConnecting::SceneConnecting(IClientLauncherPtr &client)
    : AScene(IScene::SCENE_CONNECTING), _client(client), _username(), _ip(), _port(), _selected(USERNAME)
{
    loadInfos();
    _components.emplace_back(IComponentPtr(new InputField(
            USERNAME,
            {700, 420},
            [this](const std::string &str){_username = str;},
            _selected,
            "Username",
            _username)
            ));
    _components.emplace_back(IComponentPtr(new InputField(
            PORT,
            {825, 520},
            [this](const std::string &str){_port = str;},
            _selected,
            "Port",
            _port)
    ));
    _components.emplace_back(IComponentPtr(new InputField(
            IP,
            {575, 520},
            [this](const std::string &str){_ip = str;},
            _selected,
            "IP",
            _ip)
    ));
    _components.emplace_back(IComponentPtr(new Button(
            LOGIN,
            {746, 620},
            "Login ",
            [this](){login();})
    ));
    _texture.loadFromFile(ASSETS_PATH_STR"R_type_logo.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(520, 125);
    _sprite.setScale(2, 2);
}

void SceneConnecting::render(sf::RenderWindow &win)
{
    AScene::render(win);
    win.draw(_sprite);
}

void SceneConnecting::update()
{
    AScene::update();
}

void SceneConnecting::manageEvent(const sf::Event &event, sf::RenderWindow &win)
{
    AScene::manageEvent(event, win);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab)
        _selected =_selected == USERNAME ? IP : _selected == IP ? PORT : USERNAME;
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
        login();
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        win.close();
}

void SceneConnecting::saveInfos()
{
    std::ofstream of(ASSETS_PATH_STR FILENAMEINFOS);
    of << _username + '\n' + _ip + '\n' + _port + '\n';
    of.close();
}

void SceneConnecting::loadInfos()
{
    std::ifstream input(ASSETS_PATH_STR FILENAMEINFOS);
    if (input.is_open()) {
        getline(input, _username, '\n');
        getline(input, _ip, '\n');
        getline(input, _port, '\n');
    }
    input.close();
}

void SceneConnecting::login()
{
    try {
        my_socket::IpV4 ip = my_socket::Utils::strToIp(_ip);
        my_socket::Port port = std::stoi(_port);
        _client->connect(_username, ip, port);
        saveInfos();
    } catch (...) {
        std::cout << "error" << std::endl;
    }
}