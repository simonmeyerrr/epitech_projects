/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** MyEventReceiver.cpp
*/

#include <iostream>
#include "MyEventReceiver.hpp"

MyEventReceiver::MyEventReceiver()
    : _buttonEvent(), _keyIsDown(), _textInput(false)
{
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
        _keyIsDown[i] = false;
}

bool MyEventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
            _buttonEvent.first = event.GUIEvent.Caller->getID();
            _buttonEvent.second = event.GUIEvent.EventType;
            return true;
        } else if (event.GUIEvent.EventType == irr::gui::EGET_SCROLL_BAR_CHANGED) {
            _scrollBarEvent.first = event.GUIEvent.Caller->getID();
            _scrollBarEvent.second = ((irr::gui::IGUIScrollBar *) event.GUIEvent.Caller)->getPos();
        }
        handleTextInput(event);
    } else if (event.EventType == irr::EET_KEY_INPUT_EVENT && !_textInput) {
        _keyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        _lastKey = {event.KeyInput.Key, true};
        return true;
    } else if (event.EventType == irr::EET_KEY_INPUT_EVENT && _textInput &&
        event.KeyInput.Key == 16) {
        _keyIsDown[0x37] = event.KeyInput.PressedDown;
        return true;
    }
    return false;
}

void MyEventReceiver::reset()
{
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
        _keyIsDown[i] = false;
    _buttonEvent.first = 0;
    _buttonEvent.second = static_cast<irr::gui::EGUI_EVENT_TYPE>(0);
    _lastKey.second = false;
    _scrollBarEvent.first = -1;
}

void MyEventReceiver::reset(irr::EKEY_CODE keyCode)
{
    _keyIsDown[keyCode] = false;
}

bool MyEventReceiver::isKeyDown(irr::EKEY_CODE keyCode) const
{
    return _keyIsDown[keyCode];
}

bool MyEventReceiver::isButtonClicked(irr::s32 buttonId)
{
    if (_buttonEvent.first == buttonId) {
        reset();
        return true;
    }
    return false;
}

void MyEventReceiver::handleTextInput(const irr::SEvent &event)
{
    if (event.GUIEvent.EventType == irr::gui::EGET_ELEMENT_FOCUSED
        && event.GUIEvent.Caller->getType() == irr::gui::EGUIET_EDIT_BOX) {
        _textInput = true;
    } else if (event.GUIEvent.EventType == irr::gui::EGET_ELEMENT_FOCUS_LOST
        && event.GUIEvent.Caller->getType() == irr::gui::EGUIET_EDIT_BOX) {
        _textInput = false;
    }
}

LastKey MyEventReceiver::getLastKey()
{
    return _lastKey;
}

bool MyEventReceiver::scrollBarMoved(irr::s32 scrollBarId)
{
    return _scrollBarEvent.first == scrollBarId;
}

irr::s32 MyEventReceiver::getScrollBarPos()
{
    return _scrollBarEvent.second;
}
