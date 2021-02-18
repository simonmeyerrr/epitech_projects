/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IrrlichtDevice.cpp
*/

#include "IrrlichtDevice.hpp"
#include "Config.hpp"

EventDecorator::EventDecorator(irr::IEventReceiver *receiver)
    : _receiver(receiver)
{
}

bool EventDecorator::OnEvent(const irr::SEvent &event)
{
    if (_receiver && _receiver->OnEvent(event))
        return true;
    #ifndef DEBUG
    if (event.EventType == irr::EET_LOG_TEXT_EVENT)
        return true;
    #endif
    return false;
}

IrrlichtDevice::~IrrlichtDevice()
{
    _device->drop();
    delete _eventDecorator;
}

IrrlichtDevice::IrrlichtDevice(irr::video::E_DRIVER_TYPE deviceType,
    const irr::core::dimension2d<irr::u32> &windowSize, irr::u32 bits,
    bool fullscreen, bool stencilbuffer, bool vsync,
    irr::IEventReceiver *receiver)
{
    _eventDecorator = new EventDecorator(receiver);
    _device = irr::createDevice(deviceType, windowSize, bits, fullscreen,
        stencilbuffer, vsync, _eventDecorator);
    if (!_device)
        return;
    _device->setWindowCaption(L"Indie Studio");
    _device->setResizable(true);
    irr::gui::IGUISkin *skin = gui()->getSkin();
    skin->setColor(irr::gui::EGDC_BUTTON_TEXT,
        irr::video::SColor(255, 255, 255, 255));
    skin->setColor(irr::gui::EGDC_WINDOW,
        irr::video::SColor(255, 158, 237, 255));
    skin->setColor(irr::gui::EGDC_EDITABLE,
        irr::video::SColor(255, 170, 170, 170));
    skin->setColor(irr::gui::EGDC_FOCUSED_EDITABLE,
        irr::video::SColor(255, 170, 170, 170));
    irr::gui::IGUIFont *font = gui()->getFont(ASSETS_PATH_STR
                                              "fonts/wozcott_30.xml");
    if (font)
        skin->setFont(font);
    skin->setFont(gui()->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
}

irr::IrrlichtDevice *IrrlichtDevice::operator->()
{
    return _device;
}

const irr::IrrlichtDevice *IrrlichtDevice::operator->() const
{
    return _device;
}

irr::IrrlichtDevice *IrrlichtDevice::operator*()
{
    return _device;
}

const irr::IrrlichtDevice *IrrlichtDevice::operator*() const
{
    return _device;
}

IrrlichtDevice::operator bool() const
{
    return (_device != nullptr);
}