/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** ResponsiveGui.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_RESPONSIVEGUI_HPP
# define OOP_INDIE_STUDIO_2018_RESPONSIVEGUI_HPP

#include <irrlicht/irrlicht.h>
#include <vector>
#include "IrrlichtDevice.hpp"

class ResponsiveGui {
public:
    ~ResponsiveGui();
    explicit ResponsiveGui(IrrlichtDevice &device);

    enum AlignmentX {
        ALI_X_LEFT,
        ALI_X_CENTER,
        ALI_X_RIGHT
    };

    enum AlignmentY {
        ALI_Y_UP,
        ALI_Y_CENTER,
        ALI_Y_DOWN
    };

    enum ElementType {
        ELEM_BUTTON,
        ELEM_TEXT,
        ELEM_IMAGE,
        ELEM_SCROLLBAR,
        ELEM_OTHER
    };

    using ResponsiveElement = struct responsive_element_s {
        irr::gui::IGUIElement *element;
        irr::core::vector2d<float> percent;
        irr::core::vector2d<int> size;
        AlignmentX ali_x;
        AlignmentY ali_y;
        irr::s32 id;
        ElementType type;
    };

    void addImage(const std::string &path, irr::s32 id,
        const irr::core::vector2d<float> &percent,
        AlignmentX ali_x = ALI_X_CENTER, AlignmentY ali_y = ALI_Y_CENTER);
    void addText(const wchar_t *txt, irr::s32 id,
        const irr::core::vector2d<float> &percent,
        const irr::core::vector2d<int> &size, AlignmentX ali_x = ALI_X_CENTER,
        AlignmentY ali_y = ALI_Y_CENTER);
    void addButton(const wchar_t *txt, irr::s32 id,
        const irr::core::vector2d<float> &percent,
        const irr::core::vector2d<int> &size, AlignmentX ali_x = ALI_X_CENTER,
        AlignmentY ali_y = ALI_Y_CENTER);
    void addScrollBar(irr::s32 id, bool horizontal,
        const irr::core::vector2d<float> &percent,
        const irr::core::vector2d<int> &size, int value,
        AlignmentX ali_x = ALI_X_CENTER, AlignmentY ali_y = ALI_Y_CENTER);
    void addElement(irr::gui::IGUIElement *elem,
        const irr::core::vector2d<float> &percent,
        const irr::core::vector2d<int> &size, AlignmentX ali_x = ALI_X_CENTER,
        AlignmentY ali_y = ALI_Y_CENTER, ElementType type = ELEM_OTHER);
    void drawElements();
    void updatePosition(ResponsiveElement &element);
    ResponsiveElement &getById(irr::s32 id);
    const ResponsiveElement &getById(irr::s32 id) const;
    void changeText(irr::s32 id, const std::string &txt);

private:
    IrrlichtDevice &_device;
    std::vector<ResponsiveElement> _elements;
};

#endif /* OOP_INDIE_STUDIO_2018_RESPONSIVEGUI_HPP */
