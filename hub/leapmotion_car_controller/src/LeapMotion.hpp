#ifndef LEAPDRONE_LEAPMOTION_HPP
#define LEAPDRONE_LEAPMOTION_HPP

#include <atomic>
#include <vector>
#include <mutex>
#include <Leap.h>

struct HandInfo {
    bool exist;
    float pos_x;
    float pos_y;
    float pos_z;
    float axe_x;
    float axe_y;
    float axe_z;
};

class LeapMotion : public Leap::Listener {
public:
    ~LeapMotion() override = default;
    LeapMotion();

    bool isConnected() const;
    HandInfo getHandInfo();
    std::vector<Leap::Gesture> getLastGestures();

    void onInit(const Leap::Controller &) override {}
    void onConnect(const Leap::Controller &) override {_connected = true;}
    void onDisconnect(const Leap::Controller &) override {_connected = false;}
    void onFrame(const Leap::Controller &) override;

private:
    std::mutex _mutex;
    std::atomic<bool> _connected;
    HandInfo _handInfo;
    std::vector<Leap::Gesture> _lastGestures;
};


#endif /* LEAPDRONE_LEAPMOTION_HPP */
