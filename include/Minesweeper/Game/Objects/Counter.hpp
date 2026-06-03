/*
    Counter.hpp

    Declaration of a counter UI object
*/

#pragma once

#include <World/GameObject.hpp>
#include <Components/Graphics/SpriteComponent.hpp>

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
    /**
     * @brief Constructor.
     * 
     * @param scene The scene that owns this object.
     */
    Counter(Scene& scene);

    void setValue(CounterValue value);
};
