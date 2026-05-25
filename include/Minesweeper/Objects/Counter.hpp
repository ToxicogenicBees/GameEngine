/*
    Counter.hpp

    Declaration of a counter UI object
*/

#pragma once

#include <GameObject/GameObject.hpp>
#include <Components/SpriteComponent.hpp>

enum class CounterValue {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    DASH,
    BLANK
};

class Counter : public GameObject {
private:
    SpriteComponent* sprite_;
    CounterValue value_;

    /**
     * @brief Sets the appropriate tile texture based on it's state
     */
    void updateTexture_();

public:
    Counter();

    void setValue(CounterValue value);
};
