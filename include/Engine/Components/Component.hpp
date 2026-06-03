/*
    Component.hpp

    Declaration for modular components to add to game objects
*/

#pragma once

#include "Core/Object.hpp"
#include "Core/EngineContext.hpp"

class GameObject;   // forward declaration
class Scene;        // forward declaration

class Component : public Object {
private:
    GameObject* owner_ = nullptr;

protected:
    /**
     * @brief Custom initialization logic.
     */
    virtual void onInit() {}

public:
    /**
     * @brief Constructor
     * 
     * @param owner The owner of this component.
     */
    Component(GameObject& owner);

    /**
     * @brief Gets the owner for this component.
     * 
     * @return A pointer to the owner.
     */
    GameObject* owner() const;

     /**
     * @brief Gets the scene for this component.
     * 
     * @return A pointer to the scene.
     */
    Scene* scene() const;

    /**
     * @brief Gets the engine context for this component.
     * 
     * @return A reference to the engine context.
     */
    EngineContext& context();

    /**
     * @brief Initialize the object
     */
    void init();
};
