/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Event.hpp
*/

#ifndef OOP_ARCADE_2018_EVENT_HPP
# define OOP_ARCADE_2018_EVENT_HPP

# include "Vector.hpp"

namespace arcade {

    typedef enum {
        ARCADE_NO_EVENT,
        ARCADE_CLOSE_WINDOW,
        ARCADE_KEY_A,
        ARCADE_KEY_B,
        ARCADE_KEY_C,
        ARCADE_KEY_D,
        ARCADE_KEY_E,
        ARCADE_KEY_F,
        ARCADE_KEY_G,
        ARCADE_KEY_H,
        ARCADE_KEY_I,
        ARCADE_KEY_J,
        ARCADE_KEY_K,
        ARCADE_KEY_L,
        ARCADE_KEY_M,
        ARCADE_KEY_N,
        ARCADE_KEY_O,
        ARCADE_KEY_P,
        ARCADE_KEY_Q,
        ARCADE_KEY_R,
        ARCADE_KEY_S,
        ARCADE_KEY_T,
        ARCADE_KEY_U,
        ARCADE_KEY_V,
        ARCADE_KEY_W,
        ARCADE_KEY_X,
        ARCADE_KEY_Y,
        ARCADE_KEY_Z,
        ARCADE_KEY_0,
        ARCADE_KEY_1,
        ARCADE_KEY_2,
        ARCADE_KEY_3,
        ARCADE_KEY_4,
        ARCADE_KEY_5,
        ARCADE_KEY_6,
        ARCADE_KEY_7,
        ARCADE_KEY_8,
        ARCADE_KEY_9,
        ARCADE_KEY_F1,
        ARCADE_KEY_F2,
        ARCADE_KEY_F3,
        ARCADE_KEY_F4,
        ARCADE_KEY_F5,
        ARCADE_KEY_F6,
        ARCADE_KEY_F7,
        ARCADE_KEY_F8,
        ARCADE_KEY_F9,
        ARCADE_KEY_F10,
        ARCADE_KEY_F11,
        ARCADE_KEY_F12,
        ARCADE_KEY_TAB,
        ARCADE_KEY_SPACE,
        ARCADE_KEY_ESCAPE,
        ARCADE_KEY_ENTER,
        ARCADE_KEY_DELETE,
        ARCADE_KEY_RIGHT,
        ARCADE_KEY_LEFT,
        ARCADE_KEY_UP,
        ARCADE_KEY_DOWN,
        ARCADE_CLICK_RIGHT,
        ARCADE_CLICK_LEFT
    } EventType;

    class Event {
    public:
        ~Event() = default;
        Event(EventType type, int x = 0, int y = 0);
        Event(EventType type, const Vector &v);
        Event(const Event &e);

        Event &operator=(const Event &e);
        bool operator==(const Event &e) const;
        bool operator==(const EventType &e) const;

        EventType getType() const;
        Vector getPos() const;

    private:
        EventType _type;
        Vector _pos;
    };
}

#endif /* OOP_ARCADE_2018_EVENT_HPP */
