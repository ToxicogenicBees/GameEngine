/*
    Counter.hpp

    Declaration of a counter UI object
*/

#include "Minesweeper/Game/Objects/Counter.hpp"

namespace {
    std::filesystem::path textureName(const std::string& name) {
        return "numbers/" + name + ".png";
    }
}

void Counter::updateTexture_() {
    std::filesystem::path name;
    switch(value_) {
        case(CounterValue::BLANK):
            name = textureName("blank");
            break;
        case(CounterValue::DASH):
            name = textureName("dash");
            break;
        default:
            name = textureName(std::to_string((int)value_));
    }

    auto texture = Services::assets()->loadTexture(name);
    sprite_->setTexture(texture);
}

Counter::Counter() 
    : sprite_(addComponent<SpriteComponent>(textureName("blank"))),
      value_(CounterValue::BLANK) {}

void Counter::setValue(CounterValue value) {
    value_ = value;
    updateTexture_();
}
