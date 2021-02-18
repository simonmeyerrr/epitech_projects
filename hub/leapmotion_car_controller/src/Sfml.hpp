#ifndef LEAPDRONE_SFML_HPP
#define LEAPDRONE_SFML_HPP

#include <memory>
#include <atomic>
#include <map>
#include <SFML/Graphics.hpp>

#include "LeapMotion.hpp"
#include "Drone.hpp"

class Sfml {
public:
    ~Sfml() = default;
    Sfml();

    bool isRunning() const;
    bool run();
    void stop();

private:
    void initWindow();
    void stopWindow();

    void display();
    void update();
    void event();

    std::atomic<bool> _running;
    std::atomic<bool> _stop;

    sf::Clock _displayTimer;
    sf::Clock _updateTimer;
    std::unique_ptr<sf::RenderWindow> _win;

    std::unique_ptr<LeapMotion> _listener;
    std::unique_ptr<Leap::Controller> _controller;

    enum TextId {
        LEAP_MAIN,
        LEAP_CONNECTED,
        LEAP_HAND,
        LEAP_POS,
        LEAP_AXE,
        DRONE_MAIN,
        DRONE_CONNECT,
        DRONE_BATTERY
    };

    std::unique_ptr<sf::Font> _font;
    std::map<TextId, std::unique_ptr<sf::Text>> _texts;

    std::unique_ptr<Drone> _drone;
};


#endif /* LEAPDRONE_SFML_HPP */
