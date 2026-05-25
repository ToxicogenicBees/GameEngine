/*
    Counter.hpp

    Declaration of a counter UI object
*/

#include "Minesweeper/Objects/Counter.hpp"

Counter::Counter() 
    : sprite_(addComponent<SpriteComponent>())
{
    setValue(0);
}

void Counter::setValue(int number) {
    sprite_->setTexture("numbers/" + std::to_string(number) + ".png");
}
