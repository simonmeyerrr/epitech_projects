#include "LeapMotion.hpp"

LeapMotion::LeapMotion()
    : _mutex(), _connected(false),_handInfo{false, 0, 0, 0, 0, 0, 0},
    _lastGestures()
{
}

bool LeapMotion::isConnected() const
{
    return _connected;
}

HandInfo LeapMotion::getHandInfo()
{
    _mutex.lock();
    HandInfo info = _handInfo;
    _mutex.unlock();
    return info;
}

std::vector<Leap::Gesture> LeapMotion::getLastGestures()
{
    _mutex.lock();
    std::vector<Leap::Gesture> list(_lastGestures);
    _lastGestures.clear();
    _mutex.unlock();
    return list;
}

void LeapMotion::onFrame(const Leap::Controller &controller)
{
    const Leap::Frame frame = controller.frame();

    Leap::HandList hands = frame.hands();
    HandInfo infos = {false, 0, 0, 0, 0, 0, 0};
    for (const auto &hand : hands) {
        auto pos = hand.palmPosition();
        const Leap::Vector normal = hand.palmNormal();
        const Leap::Vector direction = hand.direction();

        infos.exist = true;
        infos.pos_x = pos.x;
        infos.pos_y = pos.y;
        infos.pos_z = pos.z;
        infos.axe_x = direction.pitch() * 57.2958;
        infos.axe_y = normal.roll() * 57.2958;
        infos.axe_z = direction.yaw() * 57.2958;
        break;
    }
    _mutex.lock();
    _handInfo = infos;
    _mutex.unlock();

    const Leap::GestureList gestures = frame.gestures();
    _mutex.lock();
    for (const auto &gesture: gestures) {
        _lastGestures.push_back(gesture);
        switch (gesture.type()) {
            case Leap::Gesture::TYPE_CIRCLE:
                std::cout << "gesture type circle" << std::endl;
                break;
            case Leap::Gesture::TYPE_SWIPE:
                std::cout << "gesture type swipe" << std::endl;
                break;
            case Leap::Gesture::TYPE_KEY_TAP:
                std::cout << "gesture type key tap" << std::endl;
                break;
            case Leap::Gesture::TYPE_SCREEN_TAP:
                std::cout << "gesture type screen tap" << std::endl;
                break;
            default:
                std::cout << std::string(2, ' ')  << "Unknown gesture type." << std::endl;
        }
    }
    _mutex.unlock();
}