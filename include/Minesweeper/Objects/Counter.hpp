/*
    Counter.hpp

    Declaration of a counter UI object
*/

#pragma once

#include <GameObject/GameObject.hpp>
#include <Components/SpriteComponent.hpp>

class Counter : public GameObject {
private:
    SpriteComponent* sprite_;

public:
    Counter();

    void setValue(int number);
};
