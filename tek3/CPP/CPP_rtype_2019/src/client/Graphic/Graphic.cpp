#include "Graphic.hpp"
#include "../ClientLauncher/MyClientLauncher.hpp"
#include "../SFML/Scenes/SceneConnecting/SceneConnecting.hpp"
#include "../SFML/Scenes/SceneConnected/SceneConnected.hpp"
#include "../SFML/Scenes/SceneGame/SceneGame.hpp"

Graphic::~Graphic()
{
}

Graphic::Graphic()
    : _running(false), _stop(false), _displayTimer(), _updateTimer(),
    _win(nullptr), _client(nullptr), _oldConnected(false), _sceneType(IScene::SCENE_NONE), _scene(nullptr),
    _background(new Background())
{}

bool Graphic::isRunning() const
{
    return _running;
}

bool Graphic::run()
{
    if (_running)
        return false;

    try {
        initLauncher();
    } catch (...) {
        return false;
    }
    while (!_stop) {
        event();
        if (_win && !_stop)
            display();
        update();
    }
    stopLauncher();
    return true;
}

void Graphic::stop()
{
    _stop = true;
}

void Graphic::initLauncher()
{
    _running = true;
    _stop = false;
    _displayTimer.restart();
    _updateTimer.restart();
    _win = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "R-TYPE Launcher");
    _client = std::make_unique<MyClientLauncher>();
    _oldConnected = false;
    updateScene();
}

void Graphic::stopLauncher()
{
    _scene = nullptr;
    if (_win && _win->isOpen())
        _win->close();
    _win = nullptr;
    _client = nullptr;
    _oldConnected = false;
    _stop = false;
    _running = false;
    _sceneType = IScene::SCENE_NONE;
}

void Graphic::updateScene()
{
    if (_sceneType != IScene::SCENE_CONNECTED && _client->isConnected() && !_client->isInGame()) {
        _scene = std::make_unique<SceneConnected>(_client);
    } else if (_sceneType != IScene::SCENE_GAME && _client->isInGame()) {
        _scene = std::make_unique<SceneGame>(_client);
    } else if (_sceneType != IScene::SCENE_CONNECTING && !_client->isConnected()) {
        _scene = std::make_unique<SceneConnecting>(_client);
    } else if (!_scene) {
        _scene = std::make_unique<SceneConnecting>(_client);
    }
    _sceneType = _scene->getType();
}

void Graphic::display()
{
    auto elapsed = _displayTimer.getElapsedTime();

    if (elapsed.asMicroseconds() / 1000000.0 <= 1.0 / 30.0)
        return;
    _displayTimer.restart();
    _win->clear(sf::Color(0, 0, 25));
    if (_scene) {
        _background->render(*_win);
        _scene->render(*_win);
    }
    _win->display();
}

void Graphic::update()
{
    auto elapsed = _updateTimer.getElapsedTime();

    if (elapsed.asMicroseconds() / 1000000.0 <= 1.0 / 30.0)
        return;
    _updateTimer.restart();
    if (_client->hasErrorFetch())
        _client->disconnect();
    updateScene();
    if (_scene) {
        _background->update();
        _scene->update();
    }
}

void Graphic::event()
{
    sf::Event event;

    while (_win->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _win->close();
        else if (_scene)
            _scene->manageEvent(event, *_win);
    }
    if (!_win->isOpen())
        _stop = true;
}