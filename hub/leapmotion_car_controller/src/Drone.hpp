#ifndef LEAPMAX_DRONE_HPP
#define LEAPMAX_DRONE_HPP

#include "../lib/control.h"

class Drone {
public:
    ~Drone();
    Drone();

    bool isConnecting() const {return _connecting;}
    bool isConnected() const {return _connected;}

    void start();
    void stop();


    void move(int8_t, int8_t);
    void highJump();
    void longJump();
    void quickTurn(float angle);
    void flipUpsideDown();
    void flipDownsideUp();
    void handstandBalance();
    void quickTurnRight();
    void lookLeftAndRight();
    void tap();
    void swing();
    void quickTurnRightLeft();
    void turnAndJump();
    void turnToBalance();
    void slalom();
    void growingCircles();
    int batteryLevel();

private:
    std::unique_ptr<sumo::Control> _drone;

    std::atomic<bool> _connecting;
    std::atomic<bool> _connected;
};


#endif /* LEAPMAX_DRONE_HPP */
