/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** SceneCredit.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SCENECREDIT_HPP
# define OOP_INDIE_STUDIO_2018_SCENECREDIT_HPP

#include "../AScene.hpp"

class SceneCredit : public AScene {
public:
    enum {
        GUI_ID_RETURN = 100,
    };
    ~SceneCredit() override;
    SceneCredit(IrrlichtDevice &device, MyEventReceiver &event,
        Settings &settings, Audio &audio);

    ChangeScene update() override;
    void display(double diff) override;

private:
    irr::video::ITexture *_background;
};

#endif /* OOP_INDIE_STUDIO_2018_SCENECREDIT_HPP */
