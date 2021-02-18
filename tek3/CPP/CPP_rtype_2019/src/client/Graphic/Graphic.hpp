#ifndef CPP_RTYPE_2019_GRAPHIC_HPP
#define CPP_RTYPE_2019_GRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <atomic>
#include "../ClientLauncher/IClientLauncher.hpp"
#include "../SFML/Scenes/IScene.hpp"
#include "../SFML/Components/Background/Background.hpp"
#include "../Config.hpp"

class Graphic {
public:
    ~Graphic();
    Graphic();

    bool isRunning() const;
    bool run();
    void stop();

private:
    void initLauncher();
    void stopLauncher();
    void updateScene();

    void display();
    void update();
    void event();

    std::atomic<bool> _running;
    std::atomic<bool> _stop;

    sf::Clock _displayTimer;
    sf::Clock _updateTimer;
    std::unique_ptr<sf::RenderWindow> _win;

    IClientLauncherPtr _client;
    bool _oldConnected;
    IScene::SceneType _sceneType;
    IScenePtr _scene;
    IComponentPtr _background;
};


#endif /*CPP_RTYPE_2019_GRAPHIC_HPP*/
