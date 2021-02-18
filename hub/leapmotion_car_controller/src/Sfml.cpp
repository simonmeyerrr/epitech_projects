#include "Sfml.hpp"

Sfml::Sfml()
        : _running(false), _stop(false), _displayTimer(), _updateTimer(),
          _win(nullptr), _listener(nullptr), _controller(nullptr), _font(nullptr),
          _texts(), _drone(nullptr)
{
    _font = std::make_unique<sf::Font>();
    _font->loadFromFile("./assets/coolvetica.ttf");
}

bool Sfml::isRunning() const
{
    return _running;
}

bool Sfml::run()
{
    if (_running)
        return false;

    try {
        initWindow();
    } catch (...) {
        return false;
    }
    while (!_stop) {
        event();
        if (_win && !_stop)
            display();
        update();
    }
    stopWindow();
    return true;
}

void Sfml::stop()
{
    _stop = true;
}

void Sfml::initWindow()
{
    _running = true;
    _stop = false;
    _displayTimer.restart();
    _updateTimer.restart();
    _win = std::make_unique<sf::RenderWindow>(sf::VideoMode(600, 900), "Leap + Drone");
    _listener = std::make_unique<LeapMotion>();
    _controller = std::make_unique<Leap::Controller>();
    _controller->addListener(*_listener);
    _drone = std::make_unique<Drone>();
    _texts.insert(std::make_pair(LEAP_MAIN, std::make_unique<sf::Text>(
            "   Leap infos:\nConnected:\nHand:\nHand pos:\nHand axe:\n", *_font
            )));
    _texts.insert(std::make_pair(LEAP_CONNECTED, std::make_unique<sf::Text>(
            "false", *_font
    )));
    _texts.insert(std::make_pair(LEAP_HAND, std::make_unique<sf::Text>(
            "false", *_font
    )));
    _texts.insert(std::make_pair(LEAP_POS, std::make_unique<sf::Text>(
            "0 0 0", *_font
    )));
    _texts.insert(std::make_pair(LEAP_AXE, std::make_unique<sf::Text>(
            "0 0 0", *_font
    )));
    _texts.insert(std::make_pair(DRONE_MAIN, std::make_unique<sf::Text>(
            "   Drone infos:\nConnection:\nBattery:", *_font
    )));
    _texts.insert(std::make_pair(DRONE_CONNECT, std::make_unique<sf::Text>(
            "disconnected", *_font
    )));
    _texts.insert(std::make_pair(DRONE_BATTERY, std::make_unique<sf::Text>(
            "-1", *_font
    )));
    _texts.at(LEAP_MAIN)->setPosition({20, 20});
    _texts.at(LEAP_CONNECTED)->setPosition({150, 60});
    _texts.at(LEAP_HAND)->setPosition({150, 95});
    _texts.at(LEAP_POS)->setPosition({150, 130});
    _texts.at(LEAP_AXE)->setPosition({150, 165});
    _texts.at(DRONE_MAIN)->setPosition({250, 20});
    _texts.at(DRONE_CONNECT)->setPosition({370, 58});
    _texts.at(DRONE_BATTERY)->setPosition({370, 93});
}

void Sfml::stopWindow()
{
    if (_win && _win->isOpen())
        _win->close();
    _win = nullptr;
    _controller->removeListener(*_listener);
    _listener = nullptr;
    _controller = nullptr;
    _texts.clear();
    _stop = false;
    _running = false;
}

void Sfml::display()
{
    auto elapsed = _displayTimer.getElapsedTime();

    if (elapsed.asMicroseconds() / 1000000.0 <= 1.0 / 30.0)
        return;
    _displayTimer.restart();
    _win->clear(sf::Color::Black);
    for (const auto &text: _texts)
        _win->draw(*text.second);
    _win->display();
}

void Sfml::update()
{
    auto elapsed = _updateTimer.getElapsedTime();

    if (elapsed.asMicroseconds() / 1000000.0 <= 1.0 / 15.0)
        return;
    _updateTimer.restart();

    _texts.at(LEAP_CONNECTED)->setString(_listener->isConnected() ? "true" : "false");
    auto handInfo = _listener->getHandInfo();
    _texts.at(LEAP_HAND)->setString(handInfo.exist ? "true" : "false");
    _texts.at(LEAP_POS)->setString(std::to_string((int)handInfo.pos_x) + " " + std::to_string((int)handInfo.pos_y) + " " + std::to_string((int)handInfo.pos_z));
    _texts.at(LEAP_AXE)->setString(std::to_string((int)handInfo.axe_x) + " " + std::to_string((int)handInfo.axe_y) + " " + std::to_string((int)handInfo.axe_z));
    _texts.at(DRONE_CONNECT)->setString(_drone->isConnected() ? "connected" : _drone->isConnecting() ? "connecting" : "disconnected");
    _texts.at(DRONE_BATTERY)->setString(std::to_string(_drone->batteryLevel()));
    int accel = 0;
    int turn = 0;
    if (handInfo.exist) {
        accel = -((int)handInfo.pos_z);
        if (accel >= 127)
            accel = 127;
        if (accel <= -127)
            accel = -127;
        turn = ((int)handInfo.pos_x) / 4;
        if (turn >= 32)
            turn = 32;
        if (turn <= -32)
            turn = -32;
    }
    _drone->move(accel, turn);
}

void Sfml::event()
{
    sf::Event event;

    while (_win->pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            _win->close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
            _drone->start();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
            _drone->stop();
    }
    if (!_win->isOpen())
        _stop = true;
}