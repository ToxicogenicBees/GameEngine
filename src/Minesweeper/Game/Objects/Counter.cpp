/*
    Counter.cpp

    Implementation of a counter UI object
*/

#include "Minesweeper/Game/Objects/Counter.hpp"
#include <Core/Services.hpp>

namespace {
    std::filesystem::path textureName(const std::string& name) {
        return "counter/" + name + ".png";
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

    if (!name.empty()) {
        auto texture = Services::resources()->loadTexture(name);
        sprite_->setTexture(texture);
    }
}

Counter::Counter(Scene& scene) 
    : GameObject(scene),
      sprite_(addComponent<SpriteComponent>()),
      value_(CounterValue::BLANK)
{
    auto texture = Services::resources()->loadTexture("counter/0.png");
    sprite_->setTexture(texture);

    sprite_->setLayer(20);
}

void Counter::setValue(CounterValue value) {
    value_ = value;
    updateTexture_();
}
