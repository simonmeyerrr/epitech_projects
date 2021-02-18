/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** ResponsiveGui.cpp
*/

#include <iostream>
#include <exception>
#include <cwchar>
#include <string>
#include "ResponsiveGui.hpp"
#include "Config.hpp"

ResponsiveGui::~ResponsiveGui()
{
}

ResponsiveGui::ResponsiveGui(IrrlichtDevice &device)
    : _device(device), _elements()
{
}

void ResponsiveGui::addImage(const std::string &path, irr::s32 id,
    const irr::core::vector2d<float> &percent, ResponsiveGui::AlignmentX ali_x,
    ResponsiveGui::AlignmentY ali_y)
{
    auto texture = _device.driver()->getTexture(path.c_str());
    if (!texture) {
        return;
    }
    auto size = texture->getOriginalSize();
    auto elem = _device.gui()->addImage(texture, {0, 0}, true);
    addElement(elem, percent, {(int)size.Width, (int)size.Height}, ali_x, ali_y,
        ELEM_IMAGE);
}

void ResponsiveGui::addText(const wchar_t *txt, irr::s32 id,
    const irr::core::vector2d<float> &percent,
    const irr::core::vector2d<int> &size, ResponsiveGui::AlignmentX ali_x,
    ResponsiveGui::AlignmentY ali_y)
{
    auto elem = _device.gui()->addStaticText(txt, { 0, 0, size.X, size.Y }, false,
        true, nullptr, id);
    elem->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
    addElement(elem, percent, size, ali_x, ali_y, ELEM_TEXT);
}

void ResponsiveGui::addButton(const wchar_t *txt, irr::s32 id,
    const irr::core::vector2d<float> &percent,
    const irr::core::vector2d<int> &size, ResponsiveGui::AlignmentX ali_x,
    ResponsiveGui::AlignmentY ali_y)
{
    auto elem = _device.gui()->addButton({0, 0, size.X, size.Y}, nullptr, id,
        txt);
    elem->setAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
        irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
        irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
        irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
    if (size.X <= 40)
        elem->setImage(_device.driver()->getTexture(ASSETS_PATH_STR "textures/button_little.png"));
    else if (size.X <= 160)
        elem->setImage(_device.driver()->getTexture(ASSETS_PATH_STR "textures/button_normal.png"));
    else
        elem->setImage(_device.driver()->getTexture(ASSETS_PATH_STR "textures/button_big.png"));
    addElement(elem, percent, size, ali_x, ali_y, ELEM_BUTTON);
}

void ResponsiveGui::addScrollBar(irr::s32 id, bool horizontal,
    const irr::core::vector2d<float> &percent,
    const irr::core::vector2d<int> &size, int value,
    ResponsiveGui::AlignmentX ali_x, ResponsiveGui::AlignmentY ali_y)
{
    auto elem = _device.gui()->addScrollBar(horizontal, {0, 0, size.X, size.Y},
    nullptr, id);
    elem->setMax(100);
    elem->setPos(value);
    elem->setAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
                       irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
                       irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER,
                       irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
    addElement(elem, percent, size, ali_x, ali_y, ELEM_SCROLLBAR);
}

void ResponsiveGui::addElement(irr::gui::IGUIElement *elem,
    const irr::core::vector2d<float> &percent,
    const irr::core::vector2d<int> &size, ResponsiveGui::AlignmentX ali_x,
    ResponsiveGui::AlignmentY ali_y, ElementType type)
{
    if (!elem)
        return;
    ResponsiveElement new_elem = {elem, percent, size, ali_x, ali_y,
        elem->getID(), type};
    _elements.emplace_back(new_elem);
}

void ResponsiveGui::drawElements()
{
    for (auto &element: _elements) {
        updatePosition(element);
    }
}

void ResponsiveGui::updatePosition(ResponsiveGui::ResponsiveElement &element)
{
    irr::core::position2di pos(_device.width() * (element.percent.X / 100.0),
        _device.height() * (element.percent.Y / 100.0));

    if (element.ali_x == ALI_X_CENTER)
        pos.X -= element.size.X / 2;
    else if (element.ali_x == ALI_X_RIGHT)
        pos.X -= element.size.X;
    if (element.ali_y == ALI_Y_CENTER)
        pos.Y -= element.size.Y / 2;
    else if (element.ali_y == ALI_Y_DOWN)
        pos.Y -= element.size.Y;
    element.element->setRelativePosition(pos);
    element.element->draw();
}

const ResponsiveGui::ResponsiveElement &ResponsiveGui::getById(
    irr::s32 id) const
{
    for (auto &element: _elements) {
        if (id == element.id)
            return element;
    }
    throw std::out_of_range("Out of range GUI element");
}

ResponsiveGui::ResponsiveElement &ResponsiveGui::getById(irr::s32 id)
{
    for (auto &element: _elements) {
        if (id == element.id)
            return element;
    }
    throw std::out_of_range("Out of range GUI element");
}

void ResponsiveGui::changeText(irr::s32 id, const std::string &txt)
{
    std::wstring str(std::wstring(txt.begin(), txt.end()));
    for (auto &element: _elements) {
        if (id == element.id)
            element.element->setText(str.c_str());
    }
}
