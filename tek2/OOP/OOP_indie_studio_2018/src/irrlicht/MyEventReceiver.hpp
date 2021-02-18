/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** MyEventReceiver.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_MYEVENTRECEIVER_HPP
    #define OOP_INDIE_STUDIO_2018_MYEVENTRECEIVER_HPP

#include <irrlicht/irrlicht.h>

using GuiButtonEvent = std::pair<irr::s32, irr::gui::EGUI_EVENT_TYPE>;
using GuiScrollBarEvent = std::pair<irr::s32, irr::s32>;
using LastKey = std::pair<irr::s32, bool>;

class MyEventReceiver : public irr::IEventReceiver {
public:
    ~MyEventReceiver() override = default;
    MyEventReceiver();

    bool OnEvent(const irr::SEvent &event) override;
    bool isKeyDown(irr::EKEY_CODE keyCode) const;
    bool isButtonClicked(irr::s32 buttonId);
    bool scrollBarMoved(irr::s32 scrollBarId);
    void handleTextInput(const irr::SEvent &event);
    LastKey getLastKey();
    irr::s32 getScrollBarPos();
    void reset();
    void reset(irr::EKEY_CODE keyCode);

private:
    GuiButtonEvent _buttonEvent;
    GuiScrollBarEvent _scrollBarEvent;
    bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];
    bool _textInput;
    LastKey _lastKey;
};

#endif /* OOP_INDIE_STUDIO_2018_MYEVENTRECEIVER_HPP */
