#include <iostream>
#include "Drone.hpp"

Drone::~Drone()
{
    stop();
}

Drone::Drone()
    : _drone(nullptr), _connecting(false), _connected(false)
{
}

void Drone::start()
{
    std::cout << "start" << std::endl;
    if (!_drone && !_connecting && !_connected) {
        _connecting = true;
        _drone = std::make_unique<sumo::Control>(nullptr);
        std::cout << "start open" << std::endl;
        if (_drone->open()) {
            _connected = true;
        } else {
            _drone = nullptr;
        }
        std::cout << "end open" << std::endl;
        _connecting = false;
    }
}

void Drone::stop()
{
    if (_drone) {
        _drone->close();
        _drone->stop();
        _drone = nullptr;
    }
    _connected = false;
}

void Drone::move(int8_t a, int8_t b)
{
    if (_drone && _connected)
        _drone->move(a, b);
}

void Drone::highJump()
{
    if (_drone && _connected)
        _drone->highJump();
}

void Drone::longJump()
{
    if (_drone && _connected)
        _drone->longJump();
}

void Drone::quickTurn(float angle)
{
    if (_drone && _connected)
        _drone->quickTurn(angle);
}

void Drone::flipUpsideDown()
{
    if (_drone && _connected)
        _drone->flipUpsideDown();
}

void Drone::flipDownsideUp()
{
    if (_drone && _connected)
        _drone->flipDownsideUp();
}

void Drone::handstandBalance()
{
    if (_drone && _connected)
        _drone->handstandBalance();
}

void Drone::quickTurnRight()
{
    if (_drone && _connected)
        _drone->quickTurnRight();
}

void Drone::lookLeftAndRight()
{
    if (_drone && _connected)
        _drone->lookLeftAndRight();
}

void Drone::tap()
{
    if (_drone && _connected)
        _drone->tap();
}

void Drone::swing()
{
    if (_drone && _connected)
        _drone->swing();
}

void Drone::quickTurnRightLeft()
{
    if (_drone && _connected)
        _drone->quickTurnRightLeft();
}

void Drone::turnAndJump()
{
    if (_drone && _connected)
        _drone->turnAndJump();
}

void Drone::turnToBalance()
{
    if (_drone && _connected)
        _drone->turnToBalance();
}

void Drone::slalom()
{
    if (_drone && _connected)
        _drone->slalom();
}

void Drone::growingCircles()
{
    if (_drone && _connected)
        _drone->growingCircles();
}

int Drone::batteryLevel()
{
    if (_drone && _connected)
        return _drone->batteryLevel();
    return -1;
}