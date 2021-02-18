#ifndef LEAPMAX_MYLISTENER_HPP
#define LEAPMAX_MYLISTENER_HPP

#include <iostream>
#include <cstring>
#include "Leap.h"
#include "../lib/control.h"
#include "../lib/image.h"

namespace Leap {

    class MyListener : public Listener {
    public:
        ~MyListener();
        MyListener();
        virtual void onInit(const Controller &);
        virtual void onConnect(const Controller &);
        virtual void onDisconnect(const Controller &);
        virtual void onExit(const Controller &);
        virtual void onFrame(const Controller &);
        virtual void onFocusGained(const Controller &);
        virtual void onFocusLost(const Controller &);
        virtual void onDeviceChange(const Controller &);
        virtual void onServiceConnect(const Controller &);
        virtual void onServiceDisconnect(const Controller &);

    private:
        int _size;
        sumo::Control *_sumo;
    };
}

#endif /* LEAPMAX_MYLISTENER_HPP */
