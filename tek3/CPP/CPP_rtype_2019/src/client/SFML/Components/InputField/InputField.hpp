#ifndef CPP_RTYPE_2019_INPUTFIELD_HPP
#define CPP_RTYPE_2019_INPUTFIELD_HPP

#include <vector>
#include <string>
#include <functional>
#include "../AComponent.hpp"
#include "../../../Config.hpp"

class InputField : public AComponent {
public:
    using CallbackInput = std::function<void (const std::string &)>;


    ~InputField() override = default;
    explicit InputField(int id, sf::Vector2f pos, CallbackInput cbInput, int &selected, const std::string &placeHolder, const std::string &defaultName = "");

    void render(sf::RenderWindow &) override;
    void update() override;
    void manageEvent(const sf::Event &event, sf::RenderWindow &win) override;

private:
    int &_selected;

    sf::Font _font;

    sf::Vector2f _pos;
    sf::Vector2f _size;

    sf::RectangleShape _rect;
    sf::Text _textInput;
    sf::Text _placeHolder;

    std::string _userInput;

    CallbackInput _cbInput;
};

#endif //CPP_RTYPE_2019_INPUTFIELD_HPP
