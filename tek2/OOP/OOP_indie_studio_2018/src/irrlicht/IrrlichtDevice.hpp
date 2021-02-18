/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** IrrlichtDevice.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_IRRLICHTDEVICE_HPP
    #define OOP_INDIE_STUDIO_2018_IRRLICHTDEVICE_HPP

#include <memory>
#include <irrlicht/irrlicht.h>

class EventDecorator : public irr::IEventReceiver {
public:
    ~EventDecorator() override = default;
    explicit EventDecorator(irr::IEventReceiver *receiver);

    bool OnEvent(const irr::SEvent &event) override;
private:
    irr::IEventReceiver *_receiver;
};

class IrrlichtDevice {
public:
    ~IrrlichtDevice();
    IrrlichtDevice(irr::video::E_DRIVER_TYPE deviceType,
        const irr::core::dimension2d<irr::u32> &windowSize, irr::u32 bits,
        bool fullscreen, bool stencilbuffer, bool vsync,
        irr::IEventReceiver *receiver);

    irr::IrrlichtDevice *operator->();
    const irr::IrrlichtDevice *operator->() const;
    irr::IrrlichtDevice *operator*();
    const irr::IrrlichtDevice *operator*() const;
    explicit operator bool() const;

    irr::video::IVideoDriver *driver() {return _device->getVideoDriver();}
    irr::scene::ISceneManager *smgr() {return _device->getSceneManager();}
    irr::gui::IGUIEnvironment *gui() {return _device->getGUIEnvironment();}
    unsigned int height() {return driver()->getScreenSize().Height;}
    unsigned int width() {return driver()->getScreenSize().Width;}

private:
    irr::IrrlichtDevice *_device;
    EventDecorator *_eventDecorator;
};

#endif /* OOP_INDIE_STUDIO_2018_IRRLICHTDEVICE_HPP */
