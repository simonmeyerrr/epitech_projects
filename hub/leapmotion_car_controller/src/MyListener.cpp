#include "MyListener.hpp"

const std::string fingerNames[] = {"Thumb", "Index", "Middle", "Ring", "Pinky"};
const std::string boneNames[] = {"Metacarpal", "Proximal", "Middle", "Distal"};
const std::string stateNames[] = {"STATE_INVALID", "STATE_START", "STATE_UPDATE", "STATE_END"};

namespace Leap {
    MyListener::~MyListener()
    {
        if (_sumo) {
            _sumo->close();
            delete _sumo;
        }
    }

    MyListener::MyListener()
        : _size(0), _sumo(nullptr)
    {
        _sumo = new sumo::Control(nullptr);
        if (!_sumo->open()) {
            std::cout << "failed to open conn sumo" << std::endl;
            delete _sumo;
            _sumo = nullptr;
        } else {
            std::cout << "connection up for sumo" << std::endl;
        }
    }

    void MyListener::onInit(const Controller &controller)
    {
        std::cout << "Initialized" << std::endl;
    }

    void MyListener::onConnect(const Controller &controller)
    {
        std::cout << "Connected" << std::endl;
        controller.enableGesture(Gesture::TYPE_CIRCLE);
        controller.enableGesture(Gesture::TYPE_KEY_TAP);
        controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
        controller.enableGesture(Gesture::TYPE_SWIPE);
    }

    void MyListener::onDisconnect(const Controller &controller)
    {
        // Note: not dispatched when running in a debugger.
        std::cout << "Disconnected" << std::endl;
    }

    void MyListener::onExit(const Controller &controller)
    {
        std::cout << "Exited" << std::endl;
    }

    void MyListener::onFrame(const Controller &controller)
    {
        // Get the most recent frame and report some basic information
        const Frame frame = controller.frame();
        HandList hands = frame.hands();
        bool hasHand = false;
        //bool jump = false;
        int accel = 0;
        int turn = 0;
        for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl) {
            // Get the first hand
            const Hand hand = *hl;
            auto pos = hand.palmPosition();
            if (_size > 30) {
                _size = 0;
                std::cout << "position: " << pos << std::endl;
            } else {
                _size++;
            }
            hasHand = true;
            accel = -((int)pos.z);
            if (accel >= 127)
                accel = 127;
            if (accel <= -127)
                accel = -127;
            turn = ((int)pos.x) / 4;
            if (turn >= 32)
                turn = 32;
            if (turn <= -32)
                turn = -32;
            break;
        }
        const GestureList gestures = frame.gestures();
        for (int g = 0; g < gestures.count(); ++g) {
            Gesture gesture = gestures[g];

            switch (gesture.type()) {
                case Gesture::TYPE_CIRCLE:
                    //std::cout << "gesture type circle" << std::endl;
                    break;
                case Gesture::TYPE_SWIPE:
                    std::cout << "gesture type swipe" << std::endl;
                    break;
                case Gesture::TYPE_KEY_TAP:
                    _sumo->highJump();
                    std::cout << "gesture type key tap" << std::endl;
                    return;
                    break;
                case Gesture::TYPE_SCREEN_TAP:
                    std::cout << "gesture type screen tap" << std::endl;
                    break;
                default:
                    std::cout << std::string(2, ' ')  << "Unknown gesture type." << std::endl;
            }
        }
        if (_sumo && hasHand) {
            _sumo->move(accel, turn);
        } else if (_sumo) {
            _sumo->move(0, 0);
        }
    }

    void MyListener::onFocusGained(const Controller &controller)
    {
        std::cout << "Focus Gained" << std::endl;
    }

    void MyListener::onFocusLost(const Controller &controller)
    {
        std::cout << "Focus Lost" << std::endl;
    }

    void MyListener::onDeviceChange(const Controller &controller)
    {
        std::cout << "Device Changed" << std::endl;
        const DeviceList devices = controller.devices();

        for (int i = 0; i < devices.count(); ++i) {
            std::cout << "id: " << devices[i].toString() << std::endl;
            std::cout << "  isStreaming: " << (devices[i].isStreaming() ? "true" : "false") << std::endl;
        }
    }

    void MyListener::onServiceConnect(const Controller &controller)
    {
        std::cout << "Service Connected" << std::endl;
    }

    void MyListener::onServiceDisconnect(const Controller &controller)
    {
        std::cout << "Service Disconnected" << std::endl;
    }
}

