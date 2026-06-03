/*
    Component.hpp

    Declaration for modular components to add to game objects
*/

#pragma once

#include "Core/Object.hpp"

class GameObject;   // forward declaration
class Window;       // forward declaration

class Component : public Object {
protected:
    GameObject* owner_ = nullptr;

    friend class GameObject;

    /**
     * @brief Custom initialization logic.
     */
    virtual void onInit() {}

public:
    /**
     * @brief Constructor
     */
    Component() = default;

    /**
     * @brief Initialize the object
     */
    void init();
};
