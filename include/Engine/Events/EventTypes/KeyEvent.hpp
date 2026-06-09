/*
    KeyEvent.hpp

    Event for processing key presses
*/

#pragma once

#include "Events/EngineEvent.hpp"

enum class KeyCode {

};

struct KeyEvent : public EngineEvent {
    KeyCode key;
    bool pressed;

    /**
     * @brief Constructor
     * 
     * @param key The key this action is about
     * @param pressed If the key is pressed or not
     */
    KeyEvent(KeyCode key, bool pressed)
        : key(key), pressed(pressed) {}
};
